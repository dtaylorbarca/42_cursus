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
        self.p_height = 0.0
        self.p_age = 0

    def grow(self, growth: float) -> None:
        """
        Increase the plant height by amount.

        Args:
            growth (float): The amount of centimeters to add.
        """
        self.p_height += round(growth, 1)

    def age(self) -> None:
        """Increase the plant's age by one day."""
        self.p_age += 1

    def show(self) -> None:
        """Print current information of plant."""
        print(f"{self.name}: {self.p_height:.1f}cm, {self.p_age} days old")


def main() -> None:
    """Entry point for the growth simulation script."""
    print("=== Garden Plant Growth ===")
    rose = Plant()

    rose.name = "Rose"
    rose.p_height = 25.0
    rose.p_age = 30

    initial_height = rose.p_height
    rose.show()

    for x in range(1, 8):
        print(f"=== Day {x} ===")
        rose.grow(0.8)
        rose.age()
        rose.show()

    height_change = rose.p_height - initial_height
    print(f"Growth this week: {height_change:.1f}cm")


if __name__ == "__main__":
    main()
