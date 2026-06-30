from flyin import Parser
from pathfinder import PathFinder, PathStep
from typing import Generator


class Simulator:
    def __init__(self, parser: Parser) -> None:
        self.parser = parser
        self.COLORS: dict[str, str] = {
            "darkred": "\033[38;5;88m",
            "maroon": "\033[38;5;124m",
            "crimson": "\033[38;5;196m",
            "red": "\033[91m",
            "orange": "\033[38;5;208m",
            "gold": "\033[38;5;220m",
            "yellow": "\033[93m",
            "green": "\033[92m",
            "lime": "\033[38;5;154m",
            "cyan": "\033[96m",
            "blue": "\033[94m",
            "violet": "\033[38;5;99m",
            "purple": "\033[38;5;129m",
            "magenta": "\033[95m",
            "pink": "\033[95m",
            "brown": "\033[38;5;94m",
            "white": "\033[97m",
            "gray": "\033[90m",
            "black": "\033[30m",
            "none": "\033[97m"
        }
        self.RESET: str = "\033[0m"

    def simulate(self) -> Generator[str, None, None]:
        self.drone_states: list[list[PathStep]] = []

        for _ in range(self.parser.nb_drones):
            pathfinder = PathFinder(
                start=self.parser.start_hub,
                end=self.parser.end_hub,
            )
            path = pathfinder.find_path()
            if not path:
                raise ValueError("Path was not found for this drone")
            self.drone_states.append(path)

        current_turn = 0
        max_turns = max(len(path) for path in self.drone_states)

        while current_turn < max_turns:
            turn_moves: list[str] = []
            for drone_id, drone in enumerate(self.drone_states, 1):

                if current_turn < len(drone):
                    current_connection = drone[current_turn].connection
                    current_hub = drone[current_turn].hub
                    prev_hub = drone[current_turn - 1].hub
                    if prev_hub is None and current_hub is not None:
                        c = self.COLORS[current_hub.color]
                        r = self.RESET
                        turn_moves.append(
                            f"{c}D{drone_id}-{current_hub.name}{r}"
                        )
                    if (drone[current_turn].in_transit and
                            current_connection is not None):
                        c = self.COLORS["none"]
                        r = self.RESET
                        turn_moves.append(f"{c}D{drone_id}-"
                                          f"{current_connection.name}{r}")
                    elif (not drone[current_turn].in_transit and
                          current_hub is not None):
                        if (current_hub.name != "start" and prev_hub is not
                                None and current_hub.name != prev_hub.name):
                            c = self.COLORS[current_hub.color]
                            r = self.RESET
                            turn_moves.append(
                                f"{c}D{drone_id}-{current_hub.name}{r}")
            if turn_moves:
                result = f"Turn {current_turn}: {' '.join(turn_moves)}"
                yield result
            current_turn += 1
