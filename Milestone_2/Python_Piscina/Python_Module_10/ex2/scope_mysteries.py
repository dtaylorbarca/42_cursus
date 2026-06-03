from collections.abc import Callable
from typing import Any

def mage_counter() -> Callable[[], int]:
    calls = 0

    def counter() -> int:
        nonlocal calls
        calls += 1
        return calls
    return counter


def spell_accumulator(initial_power: int) -> Callable[[int], int]:
    power = initial_power

    def accumulate(addition: int) -> int:
        nonlocal power
        power += addition
        return power
    return accumulate


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    def enchant(item_name: str) -> str:
        return f"{enchantment_type.capitalize()} {item_name.capitalize()}"
    return enchant


def memory_vault() -> dict[str, Callable[..., Any]]:
    memory_store: dict[str, str] = {}

    def store(key: str, value: str) -> None:
        memory_store.update({key: value})

    def recall(key: str) -> str:
        try:
            return memory_store[key]
        except KeyError:
            return "Memory not found"

    return {"store": store, "recall": recall}


if __name__ == "__main__":
    # Ensure standard types are used for type hint enforcement
    print("==================================================")
    print("        BEGINNING EX2: MEMORY DEPTHS TESTS        ")
    print("==================================================\n")

    print("--- 1. Testing Mage Counter ---")
    try:
        counter_a = mage_counter()
        counter_b = mage_counter()

        print(f"counter_a call 1: {counter_a()}")
        print(f"counter_a call 2: {counter_a()}")

        print(f"counter_b call 1: {counter_b()}")
        print(f"counter_a call 3: {counter_a()}")
    except NameError:
        print("Error: mage_counter function is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during counter tracking: {e}")
    print()

    print("--- 2. Testing Spell Accumulator ---")
    try:

        fire_accumulator = spell_accumulator(100)

        print(f"Base 100, add 20: {fire_accumulator(20)}")
        print(f"Base 120, add 30: {fire_accumulator(30)}")

        ice_accumulator = spell_accumulator(50)

        print(f"New Ice Accumulator base 50, add 15: {ice_accumulator(15)}")
    except NameError:
        print("Error: spell_accumulator function is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during data accumulation: {e}")
    print()

    print("--- 3. Testing Enchantment Factory ---")
    try:

        fire_enchanter = enchantment_factory("Flaming")
        frost_enchanter = enchantment_factory("Frozen")

        print(fire_enchanter("Sword"))
        print(frost_enchanter("Shield"))
    except NameError:
        print("Error: enchantment_factory function "
              "is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during item forging: {e}")
    print()

    print("--- 4. Testing Memory Vault ---")
    try:

        vault = memory_vault()

        store_memory = vault.get('store')
        recall_memory = vault.get('recall')

        if store_memory and recall_memory:
            print("Store 'secret' = 42")
            store_memory("secret", 42)

            print("Store 'spell_formula' = 'Ignis'")
            store_memory("spell_formula", "Ignis")

            print(f"Recall 'secret': {recall_memory('secret')}")

            print(
                f"Recall 'spell_formula': '{recall_memory('spell_formula')}'")

            print(f"Recall 'unknown': {recall_memory('unknown')}")
        else:
            print(
                "Error: memory_vault dict did not return 'store' and "
                "'recall' keys correctly.")
    except NameError:
        print("Error: memory_vault function is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during memory core retrieval: {e}")
    print()

    print("==================================================")
    print("             END OF EVALUATION MATRIX             ")
    print("==================================================")
