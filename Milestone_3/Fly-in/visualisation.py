from flyin import Hub
from pathfinder import PathStep
from time import sleep
from copy import deepcopy


class Visual:
    """Renders an animated, terminal-based map of the drone simulation.

    Builds a text/ANSI-color grid from the hubs' coordinates, draws
    each hub as a small box, and then, turn by turn, redraws the grid
    with drones overlaid on the hubs and connections they currently
    occupy, animating the result in place in the terminal.
    """

    def __init__(self, coordinates: list[tuple[int, int]],
                 hubs: list[Hub], paths: list[list[PathStep]]) -> None:
        """Initialize the visualizer with map geometry and drone paths.

        Stores the list of hub coordinates (used to size the grid),
        the hubs themselves (used to draw their boxes and colors),
        and each drone's computed path (used to animate their
        movement), plus the color palette used for rendering.
        """
        self.hub_coordinates = coordinates
        self.hubs = hubs
        self.paths = paths
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

    def _clear_map(self, num_lines: int) -> None:
        """Move the cursor up and clear the previously printed map.

        Uses ANSI escape codes to move the cursor up `num_lines`
        lines and erase everything from there to the end of the
        screen, so the next frame can be redrawn in place.
        """
        print(f"\033[{num_lines}A", end="")
        print("\033[J", end="")

    def _draw_hub(self, cell: list[str], color: str) -> None:
        """Draw an empty (drone-less) hub box into a grid cell.

        Fills the middle and bottom lines of the 4-line cell with a
        colored box outline, using the color mapped from `color`
        (falling back to "none" if unrecognized).
        """
        c = self.COLORS.get(color, self.COLORS["none"])
        r = self.RESET
        cell[1] = f"{c}│         │{r}"
        cell[2] = f"{c}│         │{r}"
        cell[3] = f"{c}└─────────┘{r}"

    def _draw_drone_connection(self, cell: list[str]) -> None:
        """Draw a drone-in-transit marker onto a connection grid cell.

        Overwrites the middle two lines of the cell with a simple
        dashed/line glyph representing a drone traveling along a
        connection between two hubs.
        """
        cell[1] = "  --- ---  "
        cell[2] = "   │───│   "

    def _draw_drone_hub(self, cell: list[str], color: str) -> None:
        """Draw a drone marker inside a hub box grid cell.

        Overwrites the middle two lines of the hub's box with a
        drone glyph, keeping the box's colored side borders intact
        using the color mapped from `color` (falling back to "none"
        if unrecognized).
        """
        c = self.COLORS.get(color, self.COLORS["none"])
        r = self.RESET
        cell[1] = f"{c}│{r} --- --- {c}│{r}"
        cell[2] = f"{c}│{r}  │───│  {c}│{r}"

    def mapping(self) -> None:
        """Build the map grid and animate the simulation turn by turn.

        Computes the grid dimensions from the hubs' min/max
        coordinates, initializes a blank grid, and draws every hub's
        box onto it. Then, for each turn (starting at 1) up to the
        length of the longest drone path, makes a fresh copy of the
        base grid, overlays each active drone as either a
        connection-transit marker or a hub marker depending on its
        current PathStep, clears the previously printed frame (after
        the first), prints the new frame, and pauses briefly before
        moving to the next turn.
        """
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
