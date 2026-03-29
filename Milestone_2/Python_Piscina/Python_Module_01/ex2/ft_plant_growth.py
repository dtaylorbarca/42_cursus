"""
Module simulates plant growth over a one-week period.
It uses the Plant class to track and modify height and age.
"""


class Plant:
    """
    A plant that can grow and age.

    Attributes:
        name (str): The name of the plant.
        plant_height (int): The current height in cm.
        plant_age (int): The age in days.
    """

    def __init__(self) -> None:
        """Initialize the plant with a name, height, and age."""
        self.name: str | None = None
        self.plant_height: float = 0.0
        self.plant_age: int = 0

    def grow(self, growth: float) -> None:
        """
        Increase the plant height by amount.

        Args:
            growth (float): The amount of centimeters to add.
        """
        self.plant_height += growth

    def age(self) -> None:
        """Increase the plant's age by one day."""
        self.plant_age += 1

    def show(self) -> None:
        """Print current information of plant."""
        print(f"{self.name}: {self.plant_height:.1f}cm, {self.plant_age} days old")


def main() -> None:
    """Entry point for the growth simulation script."""
    rose = Plant()

    rose.name = "Rose"
    rose.plant_height = 25.0
    rose.plant_age = 30

    initial_height = rose.plant_height
    rose.get_info()

    for x in range(7):
        rose.grow(0.8)
        rose.age()

    rose.get_info()

    height_change = rose.plant_height - initial_height
    if height_change > 0:
        print(f"Growth this week: +{height_change}cm")
    else:
        print(f"Growth this week: {height_change}cm")


if __name__ == "__main__":
    main()
