from flyin import Hub
from heapq import heapify, heappop, heappush


class PathFinder:
    def __init__(self, start: Hub, end: Hub) -> None:
        self.start = start
        self.end = end
        self.current = start
        self.open_set: list[tuple[float, Hub]] = []
        heappush(self.open_set, (0.0, start))
    def heuristicc(self, hub: Hub) -> float:
        return abs(hub.x - self.end.x) + abs(hub.y - self.end.y)

    def find_path(self) -> list[Hub]:
        f_score, current_hub = heappop(self.open_set)
        
