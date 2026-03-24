def recursion(day) -> None:
    if day > 1:
        recursion(day - 1)
    print(f"Day {day}")


def ft_count_harvest_recursive() -> None:
    day = int(input("Days until harvest: "))
    recursion(day)
    print("Harvest time!")
