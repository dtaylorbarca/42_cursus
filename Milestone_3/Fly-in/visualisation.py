class Visual:
    def __init__(self, coordinates: list[tuple[int, int]]):
        self.hub_coordinates = coordinates

    def mapping(self) -> None:
        max_x = max(self.hub_coordinates, key=lambda x: x[0])[0]
        min_x = min(self.hub_coordinates, key=lambda x: x[0])[0]

        max_y = max(self.hub_coordinates, key=lambda x: x[1])[1]
        min_y = min(self.hub_coordinates, key=lambda x: x[1])[1]
        range_x = max_x - min_x + 1
        range_y = max_y - min_y + 1
        map = [[["       " * 3] for _ in range(range_x)]
               for _ in range(range_y)]
        for coord in self.hub_coordinates:
            x = coord[0] - min_x
            y = coord[1] - min_y
            map[y][x] = "hub"
        for row in map:
            for cell in row:
                if cell == "hub":
                    print("       ")
                    print("--- ---")
                    print(" |---| ")
                else:
                    print("       ")
                    print("       ")
                    print("       ")
