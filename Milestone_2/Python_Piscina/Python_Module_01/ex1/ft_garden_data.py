"""
Module stores and displays information about several plants in your garden.
"""


class Plant:
    """A plant in your garden."""
    def __init__(self, name, p_height, p_age):
        """Initialize the plant with a name, height, and age."""
        self.name = name
        self.p_height = p_height
        self.p_age = p_age


if __name__ == "__main__":
    rose = Plant("Rose", 25, 30)
    sflower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)
    print("=== Garden Plant Registry ===")
    print(f"{rose.name}: {rose.p_height}cm, {rose.p_age} days old")
    print(f"{sflower.name}: {sflower.p_height}cm, {sflower.p_age} days old")
    print(f"{cactus.name}: {cactus.p_height}cm, {cactus.p_age} days old")
