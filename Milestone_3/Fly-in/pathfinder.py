from flyin import Hub
from heapq import heappop, heappush


class PathFinder:
    ZONE_COSTS: dict[str, float] = {
        "normal": 1.0,
        "priority": 1.0,
        "resricted": 2.0,
        "blocked": float('inf')
    }

    def __init__(self, start: Hub, end: Hub) -> None:
        self.start = start
        self.end = end
        self.current = start
        self.open_set: list[tuple[float, Hub]] = []
        self.came_from: dict[str, Hub] = {}
        self.g_scores: dict[str, float] = {start.name: 0.0}
        self.f_scores: dict[str, float] = {start.name: self._heuristic(start)}
        self.closed_set: set[str] = set()
        heappush(self.open_set, (0.0, start))

    def _heuristic(self, hub: Hub) -> float:
        return abs(hub.x - self.end.x) + abs(hub.y - self.end.y)

    def _reconstruct_path(self, current: Hub) -> list[Hub]:
        path = [current]
        while current.name in self.came_from:
            current = self.came_from[current.name]
            path.append(current)
        path.reverse()
        return path

    def find_path(self) -> list[Hub]:
        while self.open_set:
            _, current_hub = heappop(self.open_set)
            if current_hub == self.end.name:
                return self._reconstruct_path(current_hub)
            if current_hub.name in self.closed_set:
                continue
            self.closed_set.add(current_hub.name)

            for connection in current_hub.connections:
                neighbour = (connection.hub_b if
                             connection.hub_a == current_hub.name else
                             connection.hub_a)
                if neighbour.name in self.closed_set:
                    continue
                temp_g = self.g_scores[current_hub.name] + \
                    self.ZONE_COSTS[neighbour.zone]

                if temp_g < self.g_scores.get(neighbour.name, float('inf')):
                    self.came_from[neighbour.name] = current_hub
                    self.g_scores[neighbour.name] = temp_g
                    f_score = temp_g + self._heuristic(neighbour)
                    self.f_scores[neighbour.name] = f_score
                    heappush(self.open_set, (f_score, neighbour))
