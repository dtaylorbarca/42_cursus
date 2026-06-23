from flyin import Parser
from pathfinder import PathFinder, PathStep
from typing import Generator


class Simulator:
    def __init__(self, parser: Parser) -> None:
        self.parser = parser

    def simulate(self) -> Generator[str, None, None]:
        drone_states: list[list[PathStep]] = []

        for _ in range(self.parser.nb_drones):
            pathfinder = PathFinder(
                start=self.parser.start_hub,
                end=self.parser.end_hub,
            )
            path = pathfinder.find_path()
            drone_states.append(path)

        current_turn = 0
        max_turns = max(len(path) for path in drone_states)

        while current_turn < max_turns:
            turn_moves: list[str] = []
            for drone_id, drone in enumerate(drone_states, 1):

                if current_turn < len(drone):
                    current_connection = drone[current_turn].connection
                    current_hub = drone[current_turn].hub
                    prev_hub = drone[current_turn - 1].hub
                    if (drone[current_turn].in_transit and
                            current_connection is not None):
                        turn_moves.append(current_connection.name)
                    elif (not drone[current_turn].in_transit and
                          current_hub is not None):
                        if (current_hub.name != "start" and prev_hub is not
                                None and current_hub.name != prev_hub.name):
                            turn_moves.append(
                                f"D{drone_id}-{current_hub.name}")
            if turn_moves:
                result = f"Turn {current_turn}: {' '.join(turn_moves)}"
                yield result
            current_turn += 1
