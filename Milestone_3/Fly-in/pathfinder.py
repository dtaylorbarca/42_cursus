from flyin import Hub
from heapq import heappop, heappush
from typing import Generator


class PathFinder:
    ZONE_COSTS: dict[str, float] = {
        "normal": 1.0,
        "priority": 1.0,
        "restricted": 2.0,
        "blocked": float('inf')
    }

    def __init__(self, start: Hub, end: Hub, reservations: set[tuple[str, int]]
                 ) -> None:
        self.start = start
        self.end = end
        self.current = start
        self.open_set: list[tuple[float, Hub, int]] = []
        self.came_from: dict[tuple[str, int], tuple[Hub, int]] = {}
        self.g_scores: dict[tuple[str, int], float] = {(start.name, 0): 0.0}
        self.f_scores: dict[tuple[str, int], float] = {(start.name, 0):
                                                       self._heuristic(start)}
        self.reservations: set[tuple[str, int]] = reservations
        heappush(self.open_set, (0.0, start, 0))

    def _heuristic(self, hub: Hub) -> float:
        return abs(hub.x - self.end.x) + abs(hub.y - self.end.y)

    def _reconstruct_path(self, current: Hub, turn: int) -> list[Hub]:
        path = [current]
        state = (current.name, turn)
        while state in self.came_from:
            current, turn = self.came_from[state]
            path.append(current)
            state = (current.name, turn)
        path.reverse()
        return path

    def find_path(self) -> list[Hub]:
        while self.open_set:
            _, current_hub, current_turn = heappop(self.open_set)
            if current_hub.name == self.end.name:
                return self._reconstruct_path(current_hub, current_turn)
            if current_hub.name in self.reservations:
                continue
            self.reservations.add((current_hub.name, current_turn))

            for connection in current_hub.connections:
                neighbour = (connection.hub_b if
                             connection.hub_a.name == current_hub.name else
                             connection.hub_a)
                if neighbour.name in self.reservations:
                    continue
                temp_g = self.g_scores[(current_hub.name, current_turn)] + \
                    self.ZONE_COSTS[neighbour.zone]

                arrival_turn = current_turn + \
                    int(self.ZONE_COSTS[neighbour.zone])
                if (temp_g <
                    self.g_scores.get((neighbour.name, arrival_turn),
                                      float('inf'))
                        and (neighbour.name, arrival_turn) not in
                        self.reservations):
                    self.came_from[
                        (neighbour.name, arrival_turn)] = (current_hub,
                                                           current_turn)
                    self.g_scores[(neighbour.name, arrival_turn)] = temp_g
                    f_score = temp_g + self._heuristic(neighbour)
                    self.f_scores[(neighbour.name, arrival_turn)] = f_score
                    heappush(self.open_set, (f_score, neighbour, arrival_turn))
        return []
