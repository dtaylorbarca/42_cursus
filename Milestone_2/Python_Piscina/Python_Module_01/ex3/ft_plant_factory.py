"""
Module streamlines plant creation and initialisation.
"""


class Plant:
    """A plant in your garden."""
    def __init__(self, name: str, p_height: float, p_age: int) -> None:
        """Initialize the plant with a name, height, and age."""
        self.name: str = name
        self.p_height: float = p_height
        self.p_age: int = p_age
    
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
        self.count += 1

    def show(self) -> None:
        """Prints the formatted information of the plant."""
        print(f"{self.name}: {self.p_height:.1f}cm, {self.p_age} days old")


def main() -> None:
    """Entry point for the """
    rose = Plant("Rose", 25.0, 30)
    oak = Plant("Oak", 200.0, 365)
    cactus = Plant("Cactus", 5.0, 90)
    sunflower = Plant("Sunflower", 80.0, 45)
    fern = Plant("Fern", 15.0, 120)
    
    print("Created:", end=" ")
    rose.show()
    print("Created:", end=" ")
    oak.show()
    print("Created:", end=" ")
    cactus.show()
    print("Created:", end=" ")
    sunflower.show()
    print("Created:", end=" ")
    fern.show()


if __name__ == "__main__":
    main()