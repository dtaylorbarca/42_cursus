class Visual:
    def __init__(self, coordinates: list[tuple[int, int]]):
        self.hub_coordinates = coordinates

    def _draw_hub(self, cell: list[str]) -> None:
        cell[2] = cell[2][:2] + "│" + cell[2][3:]
        cell[2] = cell[2][:12] + "│" + cell[2][13:]

        cell[3] = cell[3][:2] + "└" + cell[3][3:]
        cell[3] = cell[3][:12] + "┘" + cell[3][13:]

        cell[3] = cell[3][:3] + ("─" * 9) + cell[3][12:]

    def _draw_drone(self, cell: list[str]) -> None:
        cell[1] = cell[1][:4] + "-" * 3 + cell[1][6:7] + "-" * 3 + cell[1][10:]

        cell[2] = cell[2][:5] + "│" + ("─" * 3) + "│" + cell[2][10:]

    def mapping(self) -> None:
        max_x = max(self.hub_coordinates, key=lambda x: x[0])[0]
        min_x = min(self.hub_coordinates, key=lambda x: x[0])[0]

        max_y = max(self.hub_coordinates, key=lambda x: x[1])[1]
        min_y = min(self.hub_coordinates, key=lambda x: x[1])[1]
        range_x = max_x - min_x + 1
        range_y = max_y - min_y + 1
        map = [[["               " for _ in range(4)]
                for _ in range(range_x)]
               for _ in range(range_y)]
        for coord in self.hub_coordinates:
            self._draw_hub(map[coord[1] - min_y][coord[0] - min_x])
        for row in map:
            for internal_line in zip(*row):
                print(' '.join(internal_line))


"""        for coord in self.hub_coordinates:
            x = coord[0] - min_x
            y = coord[1] - min_y
            map[y][x] = "hub"
        index_x = 0
        index_y = 0
        while index_y < len(map):
            while index_x < len(map[0]):
                if  == "hub":
                    print("               ")
                    print("    --- ---    ")
                    print("  │  |---|  │  ")
                    print("  └─────────┘  ")
                else:
                    print("       ")
                    print("       ")
                    print("       ")
            index_y += 1"""
