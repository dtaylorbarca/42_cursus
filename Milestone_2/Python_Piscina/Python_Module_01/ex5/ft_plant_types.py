class Plant:
    """
    A plant that can grow and age.

    Attributes:
        name (str): The name of the plant.
        p_height (int): The current height in cm.
        p_age (int): The age in days.
    """
    def __init__(self, p_name: str, p_height: float, p_age: int) -> None:
        """Initialize the plant with a name and protected values."""
        self.p_name: str = p_name
        self._p_height: float = p_height
        self._p_age: int = p_age

    def grow(self, growth: float) -> None:
        """
        Increase the plant height by amount.

        Args:
            growth (float): The amount of centimeters to add.
        """
        self._p_height += growth

    def age(self) -> None:
        """Increase the plant's age by one day."""
        self._p_age += 1

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
        print(f"{self.p_name}: {self.get_height():.1f}cm,", end=" ")
        print(f"{self.get_age()} days old")


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
        self.is_bloomed: int = 0
        self.p_color: str = p_color

    def bloom(self) -> None:
        """"""
        print(f"[asking the {self.p_name} to bloom]")
        self.is_bloomed = 1

    def show(self) -> None:
        super().show()
        print(f" Color: {self.p_color}")
        if self.is_bloomed == 0:
            print(f" {self.p_name} has not bloomed yet")
        elif self.is_bloomed == 1:
            print(f" {self.p_name} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, p_name: str, p_height: float,
                 p_age: int, p_trunk_diameter: float) -> None:
        super().__init__(p_name, p_height, p_age)
        self.p_trunk_diameter: float = p_trunk_diameter
        self.is_shade: int = 0

    def produce_shade(self) -> None:
        if self.is_shade == 0:
            print(f"[asking the {self.p_name} to produce shade]")
            print(f"Tree {self.p_name} now produces a shade of", end=" ")
            self.is_shade = 1
        elif self.is_shade == 1:
            print(f"Tree {self.p_name} is already producing shade of", end=" ")
        print(f"{self.get_height():.1f}cm long", end=" ")
        print(f"and {self.p_trunk_diameter}cm wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.p_trunk_diameter:.1f}")


class Vegetable(Plant):
    def __init__(self, p_name: str, p_height: float,
                 p_age: int, p_harvest_season: str) -> None:
        super().__init__(p_name, p_height, p_age)
        self.veg_nutritional_value: int = 0
        self.p_harvest_season: str = p_harvest_season

    def grow_age(self, growth: float, days: int) -> None:
        print(f"[make {self.p_name} grow and age for {days} days]")
        for x in range(days):
            super().age()
            super().grow(growth)
            self.veg_nutritional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.p_harvest_season}")
        print(f" Nutritional value: {self.veg_nutritional_value}")


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose = Flower("Rose", 15.0, 10, "red")
    rose.show()
    rose.bloom()
    rose.show()

    print("\n=== Tree")
    oak = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    oak.produce_shade()

    print("\n=== Vegetable")
    tomato = Vegetable("Tomato", 5.0, 10, "April")
    tomato.show()
    tomato.grow_age(0.3, 20)
    tomato.show()


if __name__ == "__main__":
    main()
