def ft_count_harvest_recursive(day: int = -1) -> None:
    if day == -1:
        day = int(input("Days until harvest: "))
        ft_count_harvest_recursive(day)
        print("Harvest time!")
    else:
        if day > 1:
            ft_count_harvest_recursive(day - 1)
        print(f"Day {day}")
