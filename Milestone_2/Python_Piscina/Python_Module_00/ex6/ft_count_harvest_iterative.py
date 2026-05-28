def ft_count_harvest_iterative() -> None:
    days = int(input("Days until harvest: "))
    for count in range(1, days + 1, 1):
        print(f"Day {count}")
    print("Harvest time!")
