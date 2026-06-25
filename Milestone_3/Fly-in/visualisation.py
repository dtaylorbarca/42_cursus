from flyin import Hub
from pathfinder import PathStep
from time import sleep
from copy import deepcopy


class Visual:
    def __init__(self, coordinates: list[tuple[int, int]],
                 hubs: list[Hub], paths: list[list[PathStep]]) -> None:
        self.hub_coordinates = coordinates
        self.hubs = hubs
        self.paths = paths
        self.COLORS: dict[str, str] = {
            "red": "\033[91m",
            "green": "\033[92m",
            "yellow": "\033[93m",
            "blue": "\033[94m",
            "magenta": "\033[95m",
            "cyan": "\033[96m",
            "white": "\033[97m",
            "gray": "\033[90m",
            "orange": "\033[33m",
            "pink": "\033[95m",
            "black": "\033[30m",
            "none": "\033[97m"
        }
        self.RESET: str = "\033[0m"

    def _clear_map(self, num_lines: int) -> None:
        print(f"\033[{num_lines}A", end="")
        print("\033[J", end="")

    def _draw_hub(self, cell: list[str], color: str) -> None:
        c = self.COLORS.get(color, self.COLORS["none"])
        r = self.RESET
        cell[1] = f"{c}│         │{r}"
        cell[2] = f"{c}│         │{r}"
        cell[3] = f"{c}└─────────┘{r}"

    def _draw_drone_connection(self, cell: list[str]) -> None:
        cell[1] = "  --- ---  "
        cell[2] = "   │───│   "

    def _draw_drone_hub(self, cell: list[str], color: str) -> None:
        c = self.COLORS.get(color, self.COLORS["none"])
        r = self.RESET
        cell[1] = f"{c}│{r} --- --- {c}│{r}"
        cell[2] = f"{c}│{r}  │───│  {c}│{r}"

    def mapping(self) -> None:
        max_x = max(self.hub_coordinates, key=lambda x: x[0])[0]
        min_x = min(self.hub_coordinates, key=lambda x: x[0])[0]

        max_y = max(self.hub_coordinates, key=lambda x: x[1])[1]
        min_y = min(self.hub_coordinates, key=lambda x: x[1])[1]
        range_x = max_x - min_x + 1
        range_y = max_y - min_y + 1
        grid = [[["           " for _ in range(4)]
                for _ in range(range_x * 2 - 1)]
                for _ in range(range_y * 2 - 1)]
        for hub in self.hubs:
            self._draw_hub(grid[(max_y - hub.y) * 2][(hub.x - min_x) * 2],
                           hub.color)
        turns = len(max(self.paths, key=len))
        num_lines = 4 * (range_y * 2 - 1)
        for turn in range(1, turns):
            grid_turn = deepcopy(grid)
            for drone in self.paths:
                if turn >= len(drone):
                    continue
                current_drone = drone[turn]
                if (current_drone.in_transit and
                        current_drone.connection is not None):
                    hub_a = current_drone.connection.hub_a
                    hub_b = current_drone.connection.hub_b
                    x = hub_a.x + hub_b.x - min_x * 2
                    y = 2 * max_y - hub_a.y - hub_b.y

                    self._draw_drone_connection(grid_turn[y][x])
                elif (not current_drone.in_transit and
                        current_drone.hub is not None):
                    x = (current_drone.hub.x - min_x) * 2
                    y = (max_y - current_drone.hub.y) * 2

                    self._draw_drone_hub(grid_turn[y][x],
                                         current_drone.hub.color)
            if turn > 1:
                self._clear_map(num_lines)
            for row in grid_turn:
                for internal_line in zip(*row):
                    print(''.join(internal_line))
            sleep(0.5)
