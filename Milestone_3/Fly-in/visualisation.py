from flyin import Hub
from pathfinder import PathStep


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

    def _draw_hub(self, cell: list[str], color: str) -> None:
        c = self.COLORS.get(color, self.COLORS["none"])
        r = self.RESET
        cell[2] = f"  {c}│         │{r}  "
        cell[3] = f"  {c}└─────────┘{r}  "

    def _draw_drone_connection(self, cell: list[str]) -> None:
        cell[1] = "   --- ---   "
        cell[2] = "    │───│    "

    def _draw_drone_hub(self, cell: list[str], color: str) -> None:
        c = self.COLORS.get(color, self.COLORS["none"])
        r = self.RESET
        cell[1] = "    --- ---  "
        cell[2] = f"  {c}│{r}  │───│  {c}│{r}  "

    def mapping(self) -> None:
        max_x = max(self.hub_coordinates, key=lambda x: x[0])[0]
        min_x = min(self.hub_coordinates, key=lambda x: x[0])[0]

        max_y = max(self.hub_coordinates, key=lambda x: x[1])[1]
        min_y = min(self.hub_coordinates, key=lambda x: x[1])[1]
        range_x = max_x - min_x + 1
        range_y = max_y - min_y + 1
        map = [[["               " for _ in range(4)]
                for _ in range(range_x * 2 - 1)]
               for _ in range(range_y * 2 - 1)]
        for hub in self.hubs:
            self._draw_hub(map[(max_y - hub.y) * 2][(hub.x - min_x) * 2],
                           hub.color)
        turns = len(max(self.paths, key=len))

        for row in map:
            for internal_line in zip(*row):
                print(' '.join(internal_line))
