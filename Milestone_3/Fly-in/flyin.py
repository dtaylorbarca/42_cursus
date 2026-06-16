from __future__ import annotations
from sys import argv


class Hub:
    def __init__(self, name: str, x: int, y: int) -> None:
        self.name = name
        self.x = x
        self.y = y
        self.zone = "normal"
        self.color = "none"
        self.max_drones = 1
        self.connections: list[Connection] = []

    def __lt__(self, other: Hub) -> bool:
        return self.name < other.name

    def metadata(self, data: dict[str, str]) -> None:
        zone_types = ["normal", "blocked", "restricted", "priority"]

        if "zone" in data:
            if data["zone"] not in zone_types:
                raise ValueError(
                    f"Zone type must be one of: {', '.join(zone_types)}"
                )
            self.zone = data["zone"]

        if "color" in data:
            if len(data["color"].split()) != 1:
                raise ValueError("Color must be a single-word string")
            self.color = data["color"]

        if "max_drones" in data:
            try:
                value = int(data["max_drones"])
            except ValueError:
                raise ValueError("max_drones must be a positive integer")
            if value <= 0:
                raise ValueError("max_drones must be a positive integer")
            self.max_drones = value


class Connection:
    def __init__(self, hub_a: Hub, hub_b: Hub) -> None:
        self.hub_a = hub_a
        self.hub_b = hub_b
        self.max_link_capacity = 1

    def metadata(self, max_link_capacity: str) -> None:
        if int(max_link_capacity) <= 0:
            raise ValueError("max_link_capacity must be a positive integer")
        self.max_link_capacity = int(max_link_capacity)


class Parser:
    def __init__(self, map: str) -> None:
        self.map = map
        self.first_line = True
        self.nb_drones = 0

    def nb_drones_parse(self, key: str, value: str) -> None:
        if key != "nb_drones":
            raise SyntaxError("The first line must be of syntax "
                              "'nb_drones: <positive_integer>'")
        else:
            try:
                self.nb_drones = int(value)
                if self.nb_drones <= 0:
                    raise ValueError
            except ValueError:
                raise ValueError("The number of drones must be an integer")

    def _parse_hub(self, value: str, hub_type: str) -> Hub:
        data = value.split(" ", 3)
        if len(data) not in (3, 4):
            raise ValueError(
                f"{hub_type.capitalize()} must be in the format "
                f"'{hub_type.replace(' ', '_')}: <name> <x> <y> [metadata]'"
            )

        name = data[0].strip()

        for axis, raw in (("x", data[1]), ("y", data[2])):
            try:
                val = int(raw.strip())
                if val < 0:
                    raise ValueError
            except ValueError:
                raise ValueError(
                    f"The {axis} value in the {hub_type} must be a positive "
                    f"integer - received: {raw.strip()}"
                )

        x = int(data[1].strip())
        y = int(data[2].strip())
        hub = Hub(name, x, y)

        if len(data) == 4:
            hub = self._parse_metadata(hub, data[3], hub_type)

        return hub

    def _parse_metadata(self, hub: Hub, raw: str,
                        hub_type: str) -> Hub:
        raw = raw.strip()
        if not raw.startswith("[") or not raw.endswith("]"):
            raise SyntaxError(
                f"{hub_type.capitalize()} metadata must be enclosed "
                "with square brackets - []"
            )

        pos_metadata = {"zone", "color", "max_drones"}
        pairs = raw[1:-1].strip().split()

        if len(pairs) > len(pos_metadata):
            raise ValueError(
                f"{hub_type.capitalize()} metadata can only receive a maximum "
                f"of {len(pos_metadata)} variables: "
                f"{', '.join(pos_metadata)}"
            )

        meta: dict[str, str] = {}
        for pair in pairs:
            if "=" not in pair:
                raise SyntaxError(
                    f"{hub_type.capitalize()} metadata must have syntax "
                    f"key=value - received: {pair}"
                )
            key, val = pair.split("=", 1)
            if key not in pos_metadata:
                raise ValueError(
                    f"{hub_type.capitalize()} metadata only accepts: "
                    f"{', '.join(pos_metadata)} - received: {key}"
                )
            meta[key] = val

        hub.metadata(meta)
        return hub

    def _connection_parse(self, value: str, hubs: dict[str, Hub]) -> None:
        raw = value.strip().split()
        connection = raw[0].split("-")
        if len(connection) < 2:
            raise SyntaxError("Connections must be in the format: connection:"
                              " <name1>-<name2> [metadata]")
        elif len(connection) > 2:
            raise ValueError("The connection syntax forbids dashes in zone"
                             " names")
        hub_a_name, hub_b_name = connection
        if hub_a_name not in hubs:
            raise ValueError(f"Unknown hub; '{hub_a_name}")
        if hub_b_name not in hubs:
            raise ValueError(f"Unknown hub: '{hub_b_name}'")
        connected = Connection(hubs[hub_a_name], hubs[hub_b_name])
        if len(raw) == 2:
            connected.metadata(raw[1])
        hubs[hub_a_name].connections.append(connected)
        hubs[hub_b_name].connections.append(connected)

    def start_hub_parse(self, value: str) -> None:
        self.start_hub = self._parse_hub(value, "start hub")

    def end_hub_parse(self, value: str) -> None:
        self.end_hub = self._parse_hub(value, "end hub")

    def parse_lines(self) -> None:
        with open(self.map, "r") as f:
            file = f.read().splitlines()
        start_hubs = 0
        end_hubs = 0
        hubs: dict[str, Hub] = {}
        for row in file:
            if not row.strip():
                continue
            if row[0].strip().startswith("#"):
                continue
            if ":" not in row:
                raise SyntaxError("All lines must in the format "
                                  "'key: value'")
            key, value = map(str.strip, row.split(":", 1))
            if self.first_line:
                self.nb_drones_parse(key, value)
                self.first_line = False
                continue
            if key == "start_hub":
                start_hubs += 1
                self.start_hub_parse(value)
                hubs[self.start_hub.name] = self.start_hub
            elif key == "end_hub":
                end_hubs += 1
                self.end_hub_parse(value)
                hubs[self.end_hub.name] = self.end_hub
            elif key == "hub":
                hub = self._parse_hub(value, "hub")
                hubs[hub.name] = hub
                print("hub")
            elif key == "connection":
                print("connection")
            else:
                raise SyntaxError(f"Unkown key: '{key}'")
            if start_hubs > 1:
                raise ValueError("Only one start hub is allowed")
            if end_hubs > 1:
                raise ValueError("Only one end hub is allowed")
        if not start_hubs:
            raise SyntaxError("Start hub must be included in the map")
        if not end_hubs:
            raise SyntaxError("End hub must be included in the map")
        if (self.start_hub.x == self.end_hub.x and
                self.start_hub.y == self.end_hub.y):
            raise SyntaxError("Start and end zone must be unique")
        print(hubs)


def main() -> None:
    if len(argv) != 2:
        print("Usage: python flyin.py <map_file>")
    parser = Parser(argv[1])
    try:
        parser.parse_lines()
    except (ValueError, SyntaxError) as e:
        print(f"Error: {e}")
        exit(1)


if __name__ == "__main__":
    main()
