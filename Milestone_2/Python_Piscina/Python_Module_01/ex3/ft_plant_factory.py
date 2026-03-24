"""
Module streamlines plant creation and initialisation.
"""


class Plant:
    """A plant in your garden."""
    def __init__(self, name, p_height, p_age):
        """Initialize the plant with a name, height, and age."""
        self.name = name
        self.p_height = p_height
        self.p_age = p_age


plant_data = [
    ("Rose", 25, 30),
    ("Oak", 200, 30),
    ("Cactus", 5, 90),
    ("Sunflower", 80, 45),
    ("Fern", 15, 120)
]
garden = [Plant(name, height, age) for name, height, age in plant_data]
print("=== Plant Factory Output ===")
count = 0
for x in garden:
    print(f"Created: {x.name} ({x.p_height}cm, {x.p_age} days)")
    count += 1
print(f"\nTotal plants created: {count}")
