from flyin import Parser
from pathfinder import PathFinder, PathStep
from typing import Generator


class Simulator:
    """Runs the drone delivery simulation and produces turn-by-turn output.

    Uses PathFinder to compute a path for each drone from the parsed
    map's start hub to its end hub, then steps through the resulting
    paths turn by turn, formatting each drone's movement (arrival at
    a hub, transit along a connection) as colored text output.
    """

    def __init__(self, parser: Parser) -> None:
        """Initialize the simulator with a parsed map.

        Stores the parser (which supplies the number of drones, the
        start/end hubs, and the hub/connection graph) and sets up the
        color palettes used to format hub and connection names in the
        turn-by-turn output, including a special rainbow palette for
        hubs colored "rainbow".
        """
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
        self.RAINBOW: list[str] = [
            "\033[31m",
            "\033[33m",
            "\033[93m",
            "\033[32m",
            "\033[34m",
            "\033[35m",
            "\033[95m",
        ]
        self.RESET: str = "\033[0m"

    def simulate(self) -> Generator[str, None, None]:
        """Compute every drone's path and yield formatted per-turn moves.

        First finds a path for each drone (raising a ValueError if any
        drone has no valid path) and stores them in
        `self.drone_states`. Then iterates turn by turn up to the
        longest path's length, building a colored, human-readable
        string of each drone's move that turn (arriving at its start
        hub, transiting along a connection, or arriving at a new hub,
        with special rainbow coloring for hubs marked "rainbow") and
        yields one summary line per turn that had at least one move.
        """
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
                            if current_hub.color == "rainbow":
                                s = f"D{drone_id}-{current_hub.name}"
                                s_colored = ""
                                index = 0
                                for character in s:
                                    if index >= len(self.RAINBOW):
                                        index = 0
                                    s_colored += f"{self.RAINBOW[index]}"
                                    s_colored += f"{character}{self.RESET}"
                                    index += 1
                                turn_moves.append(s_colored)
                            else:
                                c = self.COLORS[current_hub.color]
                                r = self.RESET
                                turn_moves.append(
                                    f"{c}D{drone_id}-{current_hub.name}{r}")
            if turn_moves:
                result = f"Turn {current_turn}: {' '.join(turn_moves)}"
                yield result
            current_turn += 1
