from flyin import Parser, Hub
from pathfinder import PathFinder


class Simulator:
    def __init__(self, parser: Parser) -> None:
        self.parser = parser
        self.reservations: set[tuple[str, int]] = set()
        self.paths: list[list[Hub]] = []

    def _plan_paths(self) -> None:
        for drone_id in range(self.parser.nb_drones):
            pathfinder = PathFinder(
                start=self.parser.start_hub,
                end=self.parser.end_hub,
                reservations=self.reservations
            )
            path = pathfinder.find_path()
            if not path:
                raise ValueError(
                    f"No valid path found for drone D{drone_id + 1}")

            for turn, hub in enumerate(path):
                self.reservations.add((hub.name, turn))

            self.paths.append(path)
