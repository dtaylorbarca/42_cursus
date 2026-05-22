import sys


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory = {}
    for arg in sys.argv[1:]:
        split = arg.split(":")
        if len(split) != 2:
            print(f"Error - invalid parameter '{arg}'")
            continue
        if split[0].strip() in inventory:
            print(f"Redundant item '{split[0]}' - discarding")
            continue
        try:
            inventory.update(
                {split[0].strip(): int(split[1].strip())})
        except ValueError as e:
            print(f"Quantity error for '{split[0].strip()}': {e}")
    if inventory:
        print(f"Got inventory: {inventory}")
        print(f"Item list: {list(inventory.keys())}")
        total = sum(inventory.values())
        print(f"Total quantity of the {len(inventory)} items: {total}")
        first_item = list(inventory.keys())[0]
        m_item: str = first_item
        m_qty: int = inventory[first_item]

        l_item: str = first_item
        l_qty: int = inventory[first_item]

        for item in inventory:
            percent = round(inventory[item] / total * 100, 1)
            print(f"Item {item} represents {percent:.1f}%")

            if inventory[item] > m_qty:
                m_item = item
                m_qty = inventory[item]

        print(f"Item most abundant: {m_item} with quantity {m_qty}")

        for item in inventory:
            if inventory[item] < l_qty:
                l_item = item
                l_qty = inventory[item]

        print(f"Item least abundant: {l_item} with quantity {l_qty}")
    else:
        print("Got inventory: empty")
        print("Item list: empty")
    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
