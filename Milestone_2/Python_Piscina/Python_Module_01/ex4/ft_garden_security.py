"""
Module for Exercise 4: Garden Security System.
Implements protected attributes and controlled data access through
getters and setters to ensure data integrity.
"""


class Plant:
    def __init__(self, name: str, p_height: float, p_age: int) -> None:
        """Initialize the plant with a name and protected values."""
        self.name: str = name
        self._p_height: float = p_height
        self._p_age: int = p_age

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

    def set_height(self, height: float) -> None:
        """
        Updates the plant height with a negative value check.

        Args:
            height (float): The new height value to be set.
        """
        if height < 0:
            print("Error, height can't be negative")
            print("Height update rejected")
        else:
            self._p_height = height
            print(f"Height updated: {height:.0f}cm")

    def set_age(self, age: int) -> None:
        """
        Updates the plant age with a negative value check

        Args:
            age (int): The new age value to be set.
        """
        if age < 0:
            print("Error, age can't be negative")
            print("Age update rejected")
        else:
            self._p_age = age
            print(f"Age updated: {age} days old")

    def show(self) -> None:
        """Prints the formatted information of the plant."""
        print(f"{self.p_name}: {self.get_height():.1f}cm,", end=" ")
        print(f"{self.get_age()} days old")


def main() -> None:
    """
    Demonstrates protected attribute access via getters and setters
    """
    print("=== Garden Security System ===")
    rose = Plant("Rose", 15.0, 10)
    print(f"Plant created:", end=" ")
    rose.show()
    print("")
    rose.set_height(25.0)
    rose.set_age(30)
    print("")
    print(f"{rose.name}:", end=" ")
    rose.set_age(-10)
    print(f"{rose.name}", end=" ")
    rose.set_age(-10)
    print("")
    print(f"Current status:", end=" ")
    rose.show()


if __name__ == "__main__":
    main()
