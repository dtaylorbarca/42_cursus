from flyin import Parser, Hub
from pathfinder import PathFinder
from typing import Generator


class Simulator:
    def __init__(self, parser: Parser) -> None:
        self.parser = parser
        self.reservations: set[tuple[str, int]] = set()

    def simulate(self) -> Generator[list[str], None, None]:
        drone_states: list[list[Hub]] = []

        for _ in range(self.parser.nb_drones):
            pathfinder = PathFinder(
                start=self.parser.start_hub,
                end=self.parser.end_hub,
                reservations=self.reservations
            )
            path = pathfinder.find_path()
            drone_states.append(path)

        current_turn = 0
        max_turns = max(len(path) for path in drone_states)

        while current_turn < max_turns:
            turn_moves: list[str] = []
            for drone_id, drone in enumerate(drone_states, 1):
                if current_turn < len(drone):
                    hub = drone[current_turn]
                    turn_moves.append(f"D{drone_id}-{hub.name}")
            if turn_moves:
                yield turn_moves
            current_turn += 1
