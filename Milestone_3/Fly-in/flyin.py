from sys import argv
from typing import cast


class ParseConstraints:
    def __init__(self, map: str) -> None:
        self.map = map
        self.first_line = True
        self.nb_drones = 0

    class Hub:
        def __init__(self, name: str, x: int, y: int) -> None:
            self.name = name
            self.x = x
            self.y = y
            self.zone = "normal"
            self.color = "none"
            self.max_drones = 1

        def metadata(self, data: dict[str, str]) -> None:
            try:
                zone_types = ["normal", "blocked", "restricted", "priorty"]
                if data.get("zone"):
                    if data.get("zone") not in zone_types:
                        raise Exception("Zone types can only be one of: normal"
                                        ", blocked, restricted, priority")
                self.zone = data["zone"]
            except KeyError:
                pass
            try:
                if data.get("color"):
                    color = cast(str, data.get("color"))
                    if len(color.strip().split(" ")) != 1:
                        raise Exception("Color must be a single-word string")
                self.color = data["color"]
            except KeyError:
                pass
            try:
                if int(data["max_drones"]) <= 0:
                    raise Exception("")
                self.max_drones = data["max_drones"]
            except KeyError:
                pass
            except ValueError:
                raise Exception("Max drons needs to be a positive integer")

    def nb_drones_parse(self, key: str, value: str) -> None:
        if key != "nb_drones":
            raise Exception("The first line must be of syntax "
                            "'nb_drones: <positive_integer>'")
        else:
            try:
                self.nb_drones = int(value)
                if self.nb_drones <= 0:
                    raise ValueError
            except ValueError:
                raise Exception("The number of drones must be an integer")

    def start_hub_parse(self, value: str) -> None:
        data = value.split(" ", 3)
        if len(data) != 4 and len(data) != 3:
            raise Exception("Start hub must be in the format 'start_hub: "
                            "<name> <x> <y> [metadata]'")
        name = data[0].strip()
        try:
            x = int(data[1].strip())
            if x < 0:
                raise ValueError
        except ValueError:
            raise Exception("The x value in the start hub must be a positive "
                            f"integer - received: {data[1].strip()}")
        try:
            y = int(data[2].strip())
            if y < 0:
                raise ValueError
        except ValueError:
            raise Exception("The y value in the start hub must be a positive "
                            f"integer - received: {data[2].strip()}")
        self.start_hub = self.__class__.Hub(name, x, y)
        if len(data) == 4:
            metadata = data[3].strip()
            if (not metadata.startswith("[") or
                    not metadata.endswith("]")):
                raise Exception("Start hub metadata must be enclosed with "
                                "square brackets - []")
            metadata = metadata[1:-1].strip()
            metadata = metadata.split(" ")
            if len(metadata) > 3:
                raise Exception("Start hub metadata can only receive a maximum"
                                " of 3 variables- zone, color and/or "
                                "max_drones")
            pos_metadata = ["zone", "color", "max_drones"]
            meta = []
            index = 0
            for value in metadata:
                if "=" not in value:
                    raise Exception("Start hub metadata must have syntax"
                                    f"key=value - received: {value}")
                meta.append([])
                meta[index] = value.split("=", 1)
                index += 1
            for val in meta:
                if val[0] not in pos_metadata:
                    raise Exception("Start hub metadata can only receive these"
                                    " varibales - zone, color and/or "
                                    f"max_drones - received: {val[0]}")
            self.start_hub.metadata(dict(meta))

    def end_hub_parse(self, value: str) -> None:
        data = value.split(" ", 3)
        if len(data) != 4 and len(data) != 3:
            raise Exception("End hub must be in the format 'end_hub: "
                            "<name> <x> <y> [metadata]'")
        name = data[0].strip()
        try:
            x = int(data[1].strip())
            if x < 0:
                raise ValueError
        except ValueError:
            raise Exception("The x value in the end hub must be a positive "
                            f"integer - received: {data[1].strip()}")
        try:
            y = int(data[2].strip())
            if y < 0:
                raise ValueError
        except ValueError:
            raise Exception("The y value in the end hub must be a positive "
                            f"integer - received: {data[2].strip()}")
        self.end_hub = self.__class__.Hub(name, x, y)
        if len(data) == 4:
            metadata = data[3].strip()
            if (not metadata.startswith("[") or
                    not metadata.endswith("]")):
                raise Exception("End hub metadata must be enclosed with "
                                "square brackets - []")
            metadata = metadata[1:-1].strip()
            metadata = metadata.split(" ")
            if len(metadata) > 3:
                raise Exception("End hub metadata can only receive a maximum"
                                " of 3 variables- zone, color and/or "
                                "max_drones")
            pos_metadata = ["zone", "color", "max_drones"]
            meta = []
            index = 0
            for value in metadata:
                if "=" not in value:
                    raise Exception("End hub metadata must have syntax"
                                    f"key=value - received: {value}")
                meta.append([])
                meta[index] = value.split("=", 1)
                index += 1
            for val in meta:
                if val[0] not in pos_metadata:
                    raise Exception("End hub metadata can only receive these"
                                    " varibales - zone, color and/or "
                                    f"max_drones - received: {val[0]}")
            self.end_hub.metadata(dict(meta))

    def parse_lines(self) -> None:
        with open(self.map, "r") as f:
            file = f.read().splitlines()
            start_hubs = 0
            end_hubs = 0
            for row in file:
                if not row.strip():
                    continue
                if row[0].strip().startswith("#"):
                    continue
                if ":" not in row:
                    raise Exception("All lines must in the format "
                                    "'key: value'")
                key, value = map(str.strip, row.split(":", 1))
                if self.first_line:
                    try:
                        self.nb_drones_parse(key, value)
                    except Exception as e:
                        raise Exception(e)
                self.first_line = False
                if key == "start_hub":
                    start_hubs += 1
                    try:
                        self.start_hub_parse(value)
                    except Exception as e:
                        raise Exception(e)
                if key == "end_hub":
                    end_hubs += 1
                    try:
                        self.end_hub_parse(value)
                    except Exception as e:
                        raise Exception(e)
                if start_hubs > 1:
                    raise Exception("Only one start hub is allowed")
                if end_hubs > 1:
                    raise Exception("Only one end hub is allowed")
            if not start_hubs:
                raise Exception("Start hub must be included in the map")
            if not end_hubs:
                raise Exception("End hub must be included in the map")


def main() -> None:
    parser = ParseConstraints(argv[1])
    try:
        parser.parse_lines()
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
