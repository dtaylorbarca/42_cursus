from flyin import Hub, Connection
from heapq import heappop, heappush
from dataclasses import dataclass


@dataclass
class PathStep:
    hub: Hub | None
    connection: Connection | None
    turn: int
    in_transit: bool = False


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

    def _reconstruct_path(self, current: Hub, turn: int) -> list[PathStep]:
        path: list[PathStep] = []
        state = (current.name, turn)
        while state in self.came_from:
            prev_hub, prev_turn = self.came_from[state]
            cost = turn - prev_turn
            if cost == 2:
                path.append(PathStep(
                    hub=None,
                    connection=self._find_connection(prev_hub, current),
                    turn=prev_turn + 1,
                    in_transit=True
                ))
            path.append(PathStep(hub=current, connection=None,
                                 turn=turn))
            current = prev_hub
            turn = prev_turn
            state = (current.name, turn)
        path.append(PathStep(hub=self.start, connection=None,
                             turn=-1))
        path.reverse()
        return path

    def _find_connection(self, hub_a: Hub, hub_b: Hub) -> Connection | None:
        for connection in hub_a.connections:
            if (connection.hub_b.name == hub_b.name or
                    connection.hub_a.name == hub_b.name):
                return connection
        return None

    def _is_dead_end(self, hub: Hub) -> bool:
        if hub.name == self.end.name:
            return False
        if len(hub.connections) == 1:
            return True
        return False

    def find_path(self) -> list[PathStep]:
        closed_set: set[tuple[str, int]] = set()

        while self.open_set:
            _, current_hub, current_turn = heappop(self.open_set)

            if current_hub.name == self.end.name:
                return self._reconstruct_path(current_hub, current_turn)

            if (current_hub.name, current_turn) in closed_set:
                continue
            closed_set.add((current_hub.name, current_turn))

            found_move = False

            for connection in current_hub.connections:
                neighbour = (connection.hub_b if
                             connection.hub_a.name == current_hub.name else
                             connection.hub_a)
                arrival_turn = current_turn + \
                    int(self.ZONE_COSTS[neighbour.zone])

                if self._is_dead_end(neighbour):
                    continue
                if (connection.drones.get(current_turn, 0) >=
                        connection.max_link_capacity):
                    continue
                if (neighbour.name, arrival_turn) in closed_set:
                    continue
                if neighbour.zone == "blocked":
                    continue
                if neighbour.name == "start":
                    continue
                if (neighbour.drones.get(arrival_turn, 0) >=
                        neighbour.max_drones):
                    continue

                temp_g = (self.g_scores[(current_hub.name, current_turn)] +
                          self.ZONE_COSTS[neighbour.zone])

                if temp_g < self.g_scores.get((neighbour.name, arrival_turn),
                                              float('inf')):
                    found_move = True
                    self.reservations.add((neighbour.name, arrival_turn))
                    connection.drones[current_turn] = (
                        connection.drones.get(current_turn, 0) + 1
                    )
                    neighbour.drones[arrival_turn] = (
                        neighbour.drones.get(arrival_turn, 0) + 1
                    )
                    self.came_from[(neighbour.name, arrival_turn)] = (
                        current_hub, current_turn
                    )
                    self.g_scores[(neighbour.name, arrival_turn)] = temp_g
                    f_score = temp_g + self._heuristic(neighbour)
                    self.f_scores[(neighbour.name, arrival_turn)] = f_score
                    heappush(self.open_set, (f_score, neighbour, arrival_turn))

            if not found_move:
                wait_turn = current_turn + 1
                if (current_hub.name, wait_turn) not in closed_set:
                    wait_g = (
                        self.g_scores[(current_hub.name, current_turn)] + 1)
                    if wait_g < self.g_scores.get(
                            (current_hub.name, wait_turn), float('inf')):
                        self.came_from[(current_hub.name, wait_turn)] = (
                            current_hub, current_turn
                        )
                        current_hub.drones[current_turn] = (
                            current_hub.drones.get(current_turn, 0) + 1
                        )
                        self.g_scores[(current_hub.name, wait_turn)] = wait_g
                        f_score = wait_g + self._heuristic(current_hub)
                        heappush(self.open_set,
                                 (f_score, current_hub, wait_turn))

        return []
