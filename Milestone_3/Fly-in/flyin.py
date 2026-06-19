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
        self.drones = {}
        self.connections: list[Connection] = []

    def __lt__(self, other: Hub) -> bool:
        return self.name < other.name

    def metadata(self, data: dict[str, str]) -> None:
        zone_types = {"normal", "blocked", "restricted", "priority"}

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
        self.coordinates: set[tuple[int, int]] = set()
        self.names: set[str] = set()

    def nb_drones_parse(self, key: str, value: str, line_number: int) -> None:
        if key != "nb_drones":
            raise SyntaxError("The first line must be of syntax "
                              "'nb_drones: <positive_integer>'. Line:"
                              f" {line_number}")
        else:
            try:
                self.nb_drones = int(value)
                if self.nb_drones <= 0:
                    raise ValueError
            except ValueError:
                raise ValueError("The number of drones must be an integer. "
                                 f"Line: {line_number}")

    def parse_hub(self, value: str, hub_type: str, line_number: int) -> Hub:
        data = value.split(" ", 3)
        if len(data) not in (3, 4):
            raise ValueError(
                f"{hub_type.capitalize()} must be in the format "
                f"'{hub_type.replace(' ', '_')}: <name> <x> <y> [metadata]'."
                f"Line: {line_number}"
            )

        name = data[0].strip()

        if "-" in name or " " in name:
            raise SyntaxError("Zone names cannot use dashes or spaces. Line:"
                              f" {line_number}")
        if name in self.names:
            raise SyntaxError(f"Duplicated hub name '{name}'. Line: "
                              f"{line_number}")
        self.names.add(name)

        for axis, raw in (("x", data[1]), ("y", data[2])):
            try:
                int(raw.strip())
            except ValueError:
                raise ValueError(
                    f"The {axis} value in the {hub_type} must be an"
                    f"integer - received: {raw.strip()}. Line: {line_number}"
                )

        x = int(data[1].strip())
        y = int(data[2].strip())
        if (x, y) in self.coordinates:
            raise SyntaxError("Duplicated hub coordinates. Line: "
                              f"{line_number}")
        self.coordinates.add((x, y))
        hub = Hub(name, x, y)

        if len(data) == 4:
            hub = self._parse_metadata(hub, data[3], hub_type, line_number)

        return hub

    def _parse_metadata(self, hub: Hub, raw: str, hub_type: str,
                        line_number: int) -> Hub:
        raw = raw.strip()
        if not raw.startswith("[") or not raw.endswith("]"):
            raise SyntaxError(
                f"{hub_type.capitalize()} metadata must be enclosed "
                f"with square brackets - []. Line: {line_number}"
            )

        pos_metadata = {"zone", "color", "max_drones"}
        pairs = raw[1:-1].strip().split()

        if len(pairs) > len(pos_metadata):
            raise ValueError(
                f"{hub_type.capitalize()} metadata can only receive a maximum "
                f"of {len(pos_metadata)} variables: "
                f"{', '.join(pos_metadata)}. Line: {line_number}"
            )

        meta: dict[str, str] = {}
        for pair in pairs:
            if "=" not in pair:
                raise SyntaxError(
                    f"{hub_type.capitalize()} metadata must have syntax "
                    f"key=value - received: {pair}. Line: {line_number}"
                )
            key, val = pair.split("=", 1)
            if key not in pos_metadata:
                raise ValueError(
                    f"{hub_type.capitalize()} metadata only accepts: "
                    f"{', '.join(pos_metadata)} - received: {key}. Line: "
                    f"{line_number}"
                )
            meta[key] = val

        hub.metadata(meta)
        return hub

    def connection_parse(self, value: str, hubs: dict[str, Hub],
                         line_number: int) -> None:
        raw = value.strip().split()
        connection = raw[0].split("-")
        if len(connection) < 2:
            raise SyntaxError("Connections must be in the format: connection:"
                              " <name1>-<name2> [metadata]. Line: "
                              f"{line_number}")
        elif len(connection) > 2:
            raise ValueError("The connection syntax forbids dashes in zone"
                             f" names. Line: {line_number}")
        hub_a_name, hub_b_name = connection
        if hub_a_name not in hubs:
            raise ValueError(f"Unknown hub; '{hub_a_name}'. Line: "
                             f"{line_number}")
        if hub_b_name not in hubs:
            raise ValueError(f"Unknown hub: '{hub_b_name}'. Line: "
                             f"{line_number}")
        if hub_a_name == hub_b_name:
            raise SyntaxError("Connection paths must be between two distinct "
                              f"hubs. Line: {line_number}")
        connected = Connection(hubs[hub_a_name], hubs[hub_b_name])
        if len(raw) == 2:
            if not raw[1].startswith("[") or not raw[1].endswith("]"):
                raise SyntaxError("Connection metadata must be enclosed with "
                                  f"square brackets - []. Line: {line_number}")
            meta = raw[1][1:-1].split("=")
            if meta[0] != "max_link_capacity":
                raise SyntaxError("Only optional metadata for connections is "
                                  f"'max_link_capacity'. Received - {meta[0]}"
                                  f". Line: {line_number}")
            connected.metadata(meta[1])
        hubs[hub_a_name].connections.append(connected)
        hubs[hub_b_name].connections.append(connected)

    def start_hub_parse(self, value: str, line_number: int) -> None:
        self.start_hub = self.parse_hub(value, "start hub", line_number)

    def end_hub_parse(self, value: str, line_number: int) -> None:
        self.end_hub = self.parse_hub(value, "end hub", line_number)

    def parse_lines(self) -> None:
        with open(self.map, "r") as f:
            file = f.read().splitlines()
        line_number = 0
        start_hubs = 0
        end_hubs = 0
        hubs: dict[str, Hub] = {}
        for row in file:
            line_number += 1
            if not row.strip():
                continue
            if row[0].strip().startswith("#"):
                continue
            if ":" not in row:
                raise SyntaxError("All lines must in the format "
                                  f"'key: value'. Line: {line_number}")
            key, value = map(str.strip, row.split(":", 1))
            if self.first_line:
                self.nb_drones_parse(key, value, line_number)
                self.first_line = False
                continue
            if key == "start_hub":
                start_hubs += 1
                self.start_hub_parse(value, line_number)
                hubs[self.start_hub.name] = self.start_hub
            elif key == "end_hub":
                end_hubs += 1
                self.end_hub_parse(value, line_number)
                hubs[self.end_hub.name] = self.end_hub
            elif key == "hub":
                hub = self.parse_hub(value, "hub", line_number)
                hubs[hub.name] = hub
            elif key == "connection":
                self.connection_parse(value, hubs, line_number)
            else:
                raise SyntaxError(f"Unknown key: '{key}'. Line: {line_number}")
            if start_hubs > 1:
                raise ValueError("Only one start hub is allowed. Line: "
                                 f"{line_number}")
            if end_hubs > 1:
                raise ValueError("Only one end hub is allowed. Line: "
                                 f"{line_number}")
        if not start_hubs:
            raise SyntaxError("Start hub must be included in the map")
        if not end_hubs:
            raise SyntaxError("End hub must be included in the map")
        if (self.start_hub.x == self.end_hub.x and
                self.start_hub.y == self.end_hub.y):
            raise SyntaxError("Start and end zone must be unique")


def main() -> None:
    if len(argv) != 2:
        print("Usage: python flyin.py <map_file>")
        return
    parser = Parser(argv[1])
    try:
        parser.parse_lines()
        from simulator import Simulator
        simulator = Simulator(parser)
        for turn_moves in simulator.simulate():
            print(' '.join(turn_moves))
    except (ValueError, SyntaxError) as e:
        print(f"Error: {e}")
        exit(1)


if __name__ == "__main__":
    main()
