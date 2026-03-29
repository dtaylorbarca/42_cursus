"""
Module stores and displays information about several plants in your garden.
"""


class Plant:
    """
    A class to represent a plant in your garden.

    Attributes:
        name (str): The name of the plant species.
        p_height (int): The height of the plant in centimeters.
        p_age (int): The age of the plant in days.
    """
    def __init__(self) -> None:
        """Initializes the plant attributes with default values."""
        self.name: str | None = None
        self.p_height: int | None = None
        self.p_age: int | None = None

    def show(self) -> None:
        """Prints the formatted information of the plant."""
        print(f"{self.name}: {self.p_height}cm, {self.p_age} days old")


def main() -> None:
    """
    Entry point of the script. Instantiates plant objects,
    manually sets their attributes, and displays the registry
    """
    rose = Plant()
    sunflower = Plant()
    cactus = Plant()

    rose.name = "Rose"
    rose.p_height = 25
    rose.p_age = 30

    sunflower.name = "Sunflower"
    sunflower.p_height = 80
    sunflower.p_age = 45

    cactus.name = "Cactus"
    cactus.p_height = 15
    cactus.p_age = 120

    print("=== Garden Plant Registry ===")
    rose.show()
    sunflower.show()
    cactus.show()


if __name__ == "__main__":
    main()
