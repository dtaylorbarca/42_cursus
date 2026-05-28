def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    cap = seed_type.capitalize()
    if unit != "packets" and unit != "grams" and unit != "area":
        print("Unknown unit type")
        return
    print(f"{cap} seeds:", end=" ")
    if unit == "packets":
        print(f"{quantity} packets available")
    elif unit == "grams":
        print(f"{quantity} grams total")
    elif unit == "area":
        print(f"covers {quantity} square meters")
