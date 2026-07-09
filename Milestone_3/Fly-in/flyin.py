from __future__ import annotations
from sys import argv
from strenum import StrEnum


class TypeData(StrEnum):
    NB_DRONES = "nb_drones"
    START_HUB = "start_hub"
    END_HUB = "end_hub"
    HUB = "hub"
    CONNECTION = "connection"


class Hub:
    """Represents a single hub (node) on the drone delivery map.

    A hub has a name, a position (x, y), an optional zone type, an
    optional color, a maximum number of drones it can hold, a record
    of the drones currently present, and the list of connections that
    link it to other hubs.
    """

    def __init__(self, name: str, x: int, y: int) -> None:
        """Initialize a hub with its name and coordinates.

        Sets sensible defaults for zone ("normal"), color ("none"),
        max_drones (1), and empty containers for drones and
        connections.
        """
        self.name = name
        self.x = x
        self.y = y
        self.zone = "normal"
        self.color = "none"
        self.max_drones = 1
        self.drones: dict[int, int] = {}
        self.connections: list[Connection] = []

    def __lt__(self, other: Hub) -> bool:
        """Compare hubs by name so that they can be sorted."""
        return self.name < other.name

    def metadata(self, data: dict[str, str], line_number: int) -> None:
        """Apply optional metadata (zone, color, max_drones) to the hub.

        Validates each provided key against its expected format/type
        and raises a ValueError with the offending line number if any
        value is invalid. Only keys present in `data` are applied;
        unspecified attributes keep their default values.
        """
        zone_types = {"normal", "blocked", "restricted", "priority"}

        if "zone" in data:
            if data["zone"] not in zone_types:
                raise ValueError(
                    f"Zone type must be one of: {', '.join(zone_types)}"
                    f". Line: {line_number}"
                )
            self.zone = data["zone"]

        if "color" in data:
            if len(data["color"].split()) != 1:
                raise ValueError("Color must be a single-word string"
                                 f". Line: {line_number}")
            self.color = data["color"]

        if "max_drones" in data:
            try:
                value = int(data["max_drones"])
            except ValueError:
                raise ValueError("max_drones must be a positive integer"
                                 f". Line: {line_number}")
            if value <= 0:
                raise ValueError("max_drones must be a positive integer"
                                 f". Line: {line_number}")
            self.max_drones = value


class Connection:
    """Represents a link between two hubs that drones can travel along.

    Stores the pair of connected hubs, the maximum number of drones
    that may use the link concurrently (`max_link_capacity`), and a
    record of drones currently occupying the connection.
    """

    def __init__(self, hub_a: Hub, hub_b: Hub) -> None:
        """Initialize a connection between hub_a and hub_b.

        Defaults max_link_capacity to 1 and starts with no drones on
        the connection.
        """
        self.hub_a = hub_a
        self.hub_b = hub_b
        self.max_link_capacity = 1
        self.drones: dict[int, int] = {}

    @property
    def name(self) -> str:
        """Return a canonical, order-independent name for the connection.

        The two hub names are sorted alphabetically and joined with a
        dash, e.g. "A-B", regardless of which hub was passed first.
        """
        names = sorted([self.hub_a.name, self.hub_b.name])
        return f"{names[0]}-{names[1]}"

    def metadata(self, max_link_capacity: str, line_number: int) -> None:
        """Set the connection's max_link_capacity from a string value.

        Raises a ValueError (including the line number) if the value
        is not a positive integer.
        """
        if int(max_link_capacity) <= 0:
            raise ValueError("max_link_capacity must be a positive integer."
                             f"Line: {line_number}")
        self.max_link_capacity = int(max_link_capacity)


class Parser:
    """Parses a map definition file into hubs, connections, and drones.

    Reads the file line by line, validating syntax and building up
    the set of hubs (including the designated start and end hubs),
    the connections between them, and the total number of drones to
    simulate.
    """

    def __init__(self, map: str) -> None:
        """Initialize the parser with the path to the map file.

        Sets up empty tracking structures for the number of drones,
        used coordinates, used hub names, used connections, and the
        list of parsed hubs.
        """
        self.map = map
        self.nb_drones = 0
        self.coordinates: set[tuple[int, int]] = set()
        self.names: set[str] = set()
        self.connections: set[tuple[str, str]] = set()
        self.hubs: list[Hub] = []

    def _nb_drones_parse(self, key: str, value: str, line_number: int) -> None:
        """Parse the mandatory first line declaring the number of drones.

        Verifies that the key is exactly "nb_drones" and that its
        value is a positive integer, raising SyntaxError/ValueError
        with the line number otherwise.
        """
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
                raise ValueError("The number of drones must be a positive"
                                 f" integer. Line: {line_number}")

    def _parse_hub(self, value: str, hub_type: str, line_number: int) -> Hub:
        """Parse a single hub definition line into a Hub object.

        Expects `value` to contain the hub name, x, y, and optionally
        a metadata block, separated by spaces. Validates the name
        (no dashes/spaces, not a duplicate), the coordinates (valid
        integers, not duplicated), applies any metadata, registers
        the hub in self.hubs, and returns it.
        """
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
                    f"The {axis} value in the {hub_type} must be an "
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
        self.hubs.append(hub)
        return hub

    def _parse_metadata(self, hub: Hub, raw: str, hub_type: str,
                        line_number: int) -> Hub:
        """Parse a hub's bracketed metadata block and apply it to the hub.

        Validates that `raw` is enclosed in square brackets, splits it
        into "key=value" pairs, checks that only recognized metadata
        keys (zone, color, max_drones) are used and that the number
        of pairs doesn't exceed the allowed maximum, then delegates
        the actual value validation/assignment to Hub.metadata.
        """
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
            if len(pair.split("=")) != 2:
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
        hub.metadata(meta, line_number)
        return hub

    def _connection_parse(self, value: str, hubs: dict[str, Hub],
                          line_number: int) -> None:
        """Parse a connection definition line and link the two hubs.

        Expects `value` to contain "<name1>-<name2>" optionally
        followed by a bracketed max_link_capacity metadata block.
        Validates that both hub names exist, are distinct, and that
        the connection (in either direction) hasn't already been
        defined, then creates a Connection and appends it to both
        hubs' connection lists.
        """
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
        if (hub_a_name, hub_b_name) in self.connections:
            raise ValueError("The same connection must not appear more than "
                             f"once. Line: {line_number}")
        elif (hub_b_name, hub_a_name) in self.connections:
            raise ValueError("The same connection must not appear more than "
                             f"once (even reversed). Line: {line_number}")
        else:
            self.connections.add((hub_a_name, hub_b_name))
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
            connected.metadata(meta[1], line_number)
        hubs[hub_a_name].connections.append(connected)
        hubs[hub_b_name].connections.append(connected)

    def _start_hub_parse(self, value: str, line_number: int) -> None:
        """Parse the start_hub line and store it as self.start_hub."""
        self.start_hub = self._parse_hub(value, "start hub", line_number)

    def _end_hub_parse(self, value: str, line_number: int) -> None:
        """Parse the end_hub line and store it as self.end_hub."""
        self.end_hub = self._parse_hub(value, "end hub", line_number)

    def parse_lines(self) -> None:
        """Read and parse the entire map file.

        Opens the map file, then processes it line by line: the first
        non-empty, non-comment line must declare nb_drones; subsequent
        lines may declare hubs, the start hub, the end hub, or
        connections between hubs. Enforces that exactly one start hub
        and one end hub are present, that they don't occupy the same
        coordinates, and raises SyntaxError/ValueError/OSError with
        line numbers on any malformed input.
        """
        try:
            with open(self.map, "r") as f:
                file = f.read().splitlines()
        except OSError as e:
            raise OSError(e)
        first_line = True
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
            if first_line:
                self._nb_drones_parse(key, value, line_number)
                first_line = False
                continue
            match key:
                case TypeData.START_HUB:
                    start_hubs += 1
                    self._start_hub_parse(value, line_number)
                    hubs[self.start_hub.name] = self.start_hub
                case TypeData.END_HUB:
                    end_hubs += 1
                    self._end_hub_parse(value, line_number)
                    hubs[self.end_hub.name] = self.end_hub
                case TypeData.HUB:
                    hub = self._parse_hub(value, "hub", line_number)
                    hubs[hub.name] = hub
                case TypeData.CONNECTION:
                    self._connection_parse(value, hubs, line_number)
                case TypeData.NB_DRONES:
                    if not first_line:
                        raise SyntaxError("nb_drones can only be defined in "
                                          "the first line. Line: "
                                          f"{line_number}")
                case _:
                    raise SyntaxError(
                        f"Unknown key: '{key}'. Line: {line_number}")
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


if __name__ == "__main__":
    if len(argv) != 2:
        print("Usage: python flyin.py <map_file>")
        exit(1)
    parser = Parser(argv[1])
    try:
        parser.parse_lines()
        from simulator import Simulator
        simulator = Simulator(parser)
        print("")
        for turn_moves in simulator.simulate():
            print(turn_moves)
        from visualisation import Visual
        vis = Visual(list(parser.coordinates), parser.hubs,
                     simulator.drone_states)
        vis.mapping()
    except (ValueError, SyntaxError, OSError) as e:
        print(f"Error: {e}")
        exit(1)
