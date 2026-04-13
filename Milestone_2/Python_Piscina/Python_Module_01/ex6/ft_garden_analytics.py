class Plant:
    """
    A plant that can grow and age.

    Attributes:
        name (str): The name of the plant.
        p_height (int): The current height in cm.
        p_age (int): The age in days.
    """
    class Stats:
        def __init__(self) -> None:
            self.grow_calls: int = 0
            self.age_calls: int = 0
            self.show_calls: int = 0

        def get_stats(self) -> None:
            print(f"Stats: {self.grow_calls} grow,", end=" ")
            print(f"{self.age_calls} age, {self.show_calls} show")

    def __init__(self, p_name: str, p_height: float, p_age: int) -> None:
        """Initialize the plant with a name and protected values."""
        self.p_name: str = p_name
        self._p_height: float = round(p_height, 1)
        self._p_age: int = p_age
        self._stats = self.Stats()

    def grow(self, growth: float) -> None:
        """
        Increase the plant height by amount.

        Args:
            growth (float): The amount of centimeters to add.
        """
        self._p_height = round(self._p_height + round(growth, 1), 1)
        self._stats.grow_calls += 1

    def age(self) -> None:
        """Increase the plant's age by one day."""
        self._p_age += 1
        self._stats.age_calls += 1

    def get_height(self) -> float:
        """
        Returns the current plant height.

        Returns:
            float: The current height of the plant.
        """
        return self._p_height

    def get_age(self) -> int:
        """
        Returns the current plant age.

        Returns:
            int: The current age of the plant.
        """
        return self._p_age

    def set_height(self, p_height: float) -> None:
        """
        Updates the plant height with a negative value check.

        Args:
            height (float): The new height value to be set.
        """
        if p_height < 0:
            print("Error, height can't be negative")
            print("Height update rejected")
        else:
            self._p_height = p_height
            print(f"Height updated: {p_height:.0f}cm")

    def set_age(self, p_age: int) -> None:
        """
        Updates the plant age with a negative value check

        Args:
            age (int): The new age value to be set.
        """
        if p_age < 0:
            print("Error, age can't be negative")
            print("Age update rejected")
        else:
            self._p_age = p_age
            print(f"Age updated: {p_age} days old")

    def show(self) -> None:
        """Prints the formatted information of the plant."""
        print(f"{self.p_name}: {self.get_height()}cm,", end=" ")
        print(f"{self.get_age()} days old")
        self._stats.show_calls += 1

    @staticmethod
    def age_check(age: int) -> bool:
        return age > 365

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    """
    A flower that can bloom.

    Attributes:
        name (str): The name of the plant.
        p_height (int): The current height in cm.
        p_age (int): The age in days.
        p_color (str): The color of the flower.
    """
    def __init__(self, p_name: str, p_height: float,
                 p_age: int, p_color: str) -> None:
        """Initialize the parent class and the color."""
        super().__init__(p_name, p_height, p_age)
        self.is_bloomed: bool = False
        self.p_color: str = p_color

    def bloom(self) -> None:
        self.is_bloomed = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.p_color}")
        if not self.is_bloomed:
            print(f" {self.p_name} has not bloomed yet")
        else:
            print(f" {self.p_name} is blooming beautifully!")

    def get_stats(self) -> None:
        self._stats.get_stats()


class Tree(Plant):
    def __init__(self, p_name: str, p_height: float,
                 p_age: int, p_trunk_diameter: float) -> None:
        super().__init__(p_name, p_height, p_age)
        self.p_trunk_diameter: float = round(p_trunk_diameter, 1)
        self.shade_calls: int = 0

    def produce_shade(self) -> None:
        print(f"Tree {self.p_name} now produces a shade of", end=" ")
        print(f"{self._p_height}cm long and {self.p_trunk_diameter}cm wide.")
        self.shade_calls += 1

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.p_trunk_diameter}")

    def get_stats(self) -> None:
        self._stats.get_stats()
        print(f" {self.shade_calls} shade")


class Vegetable(Plant):
    def __init__(self, p_name: str, p_height: float,
                 p_age: int, p_harvest_season: str) -> None:
        super().__init__(p_name, p_height, p_age)
        self.veg_nutritional_value: int = 0
        self.p_harvest_season: str = p_harvest_season

    def grow_age(self, growth: float, days: int) -> None:
        for x in range(days):
            self.age()
            self.grow(growth)
            self.veg_nutritional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.p_harvest_season}")
        print(f" Nutritional value: {self.veg_nutritional_value}")

    def get_stats(self) -> None:
        self._stats.get_stats()


class Seed(Flower):
    def __init__(self, p_name: str, p_height: float,
                 p_age: int, p_color: str) -> None:
        super().__init__(p_name, p_height, p_age, p_color)
        self.seed_count: int = 0

    def bloom(self, seeds: int = 0) -> None:
        super().bloom()
        self.seed_count = seeds

    def show(self) -> None:
        super().show()
        print(f" Seed: {self.seed_count}")

    def get_stats(self) -> None:
        self._stats.get_stats()


def statistics() -> None:
    print("=== Garden statistics ===")

    print("=== Check year-old")
    print("Is 30 days more than a year? ->", end=" ")
    print(Plant.age_check(30))
    print("Is 400 days more than a year? ->", end=" ")
    print(Plant.age_check(400))

    print("\n=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print("[statistics for Rose]")
    rose.get_stats()
    print("[asking the rose to grow and bloom]")
    rose.bloom()
    rose.grow(8.0)
    rose.show()
    print("[statistics for Rose]")
    rose.get_stats()

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print("[statistics for Oak]")
    oak.get_stats()
    oak.produce_shade()
    print("[statistics for Oak]")
    oak.get_stats()

    print("\n=== Seed")
    sunflower = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.bloom()
    sunflower.grow(30.0)
    for x in range(20):
        sunflower.age()
    sunflower.show()
    print("[statistics for Sunflower]")
    sunflower.get_stats()

    print("\n=== Anonymous")
    anonymous = Plant.anonymous()
    anonymous.show()
    print("[statistics for Unknown plant]")
    anonymous._stats.get_stats()


def main() -> None:
    statistics()


if __name__ == "__main__":
    main()
