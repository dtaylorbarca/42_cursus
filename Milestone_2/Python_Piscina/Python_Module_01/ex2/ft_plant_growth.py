"""
Module simulates plant growth over a one-week period.
It uses the Plant class to track and modify height and age.
"""


class Plant:
    """A plant that can grow and age."""

    def __init__(self, name, plant_height, plant_age):
        """Initialize the plant with a name, height, and age."""
        self.name = name
        self.plant_height = plant_height
        self.plant_age = plant_age
        self.count = 1

    def grow(self, growth):
        """Increase the plant height by amount."""
        self.plant_height += growth

    def age(self):
        """Increase the plant's age by one day."""
        self.plant_age += 1
        self.count += 1

    def get_info(self):
        """Print current information of plant."""
        print(f"=== Day {self.count} ===")
        print(f"{self.name}: {self.plant_height}cm, {self.plant_age} days old")


if __name__ == "__main__":
    rose = Plant("Rose", 25, 30)
    rose.get_info()
    intial_height = rose.plant_height
    for x in range(6):
        rose.grow(1)
        rose.age()
    rose.get_info()
    height_change = rose.plant_height - intial_height
    if height_change > 0:
        print(f"Growth this week: +{height_change}cm")
    else:
        print(f"Growth this week: {height_change}cm")
