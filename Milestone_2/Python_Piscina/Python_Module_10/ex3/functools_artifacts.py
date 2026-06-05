from functools import reduce, partial, lru_cache, singledispatch
from collections.abc import Callable
from typing import Any
from operator import add, mul


class OperationError(Exception):
    def __init__(self, message: str = "Invalid operation") -> None:
        super().__init__(message)


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    if operation == "add":
        return reduce(add, spells)
    elif operation == "multiply":
        return reduce(mul, spells)
    elif operation == "max":
        return reduce(max, spells)
    elif operation == "min":
        return reduce(min, spells)
    else:
        raise OperationError


def partial_enchanter(base_enchantment: Callable[[int, str, str], str]
                      ) -> dict[str, Callable[[str], str]]:
    enchant_1 = partial(base_enchantment, 50, "fire")
    enchant_2 = partial(base_enchantment, 50, "ice")
    enchant_3 = partial(base_enchantment, 50, "lightning")
    return {
        "fire": enchant_1,
        "ice": enchant_2,
        "lightning": enchant_3
    }


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n == 1:
        return 1
    if n == 0:
        return 0
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n-2)


def spell_dispatcher() -> Callable[[Any], str]:
    @singledispatch
    def cast(spell: Any) -> str:
        return "Unknown spell type"

    @cast.register(int)
    def _(spell: int) -> str:
        return f"{spell} damage"

    @cast.register(str)
    def _(spell: str) -> str:
        return spell

    @cast.register(list)
    def _(spell: list[str]) -> str:
        return f"{len(spell)} spells"

    return cast


if __name__ == "__main__":
    print("==================================================")
    print("       BEGINNING EX3: ANCIENT LIBRARY TESTS       ")
    print("==================================================\n")
    print("--- 1. Testing Spell Reducer ---")
    try:
        spell_powers = [10, 20, 30, 40]
        print(f"Base spell powers array: {spell_powers}")

        print(f"Sum (add): {spell_reducer(spell_powers, 'add')}")
        print(f"Product (multiply): {spell_reducer(spell_powers, 'multiply')}")
        print(f"Max: {spell_reducer(spell_powers, 'max')}")
        print(f"Min: {spell_reducer(spell_powers, 'min')}")

        print(f"Empty list reduction: {spell_reducer([], 'add')}")

        print("Testing unknown operation error handling:")
        error_result = spell_reducer(spell_powers, "levitate")
        print(f"  Result for unknown operation: {error_result}")
    except NameError:
        print("Error: spell_reducer function is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during spell reduction: {e}")
    print()

    print("--- 2. Testing Partial Enchanter ---")
    try:
        def base_enchantment(power: int, element: str, target: str) -> str:
            return f"Enchanted {target} with {element} (Power: {power})"

        enchanters_dict = partial_enchanter(base_enchantment)

        if isinstance(enchanters_dict, dict):
            if "fire" in enchanters_dict:
                print(f"Fire Enchanter: {enchanters_dict['fire']('Sword')}")
            if "ice" in enchanters_dict:
                print(f"Ice Enchanter: {enchanters_dict['ice']('Shield')}")
            if "lightning" in enchanters_dict:
                print("Lightning Enchanter: "
                      f"{enchanters_dict['lightning']('Staff')}")
        else:
            print("Error: partial_enchanter did not return "
                  "a dictionary mapping elements.")
    except NameError:
        print("Error: partial_enchanter function is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during partial application execution: {e}")
    print()

    print("--- 3. Testing Memoized Fibonacci ---")
    try:
        print(f"Fib(0): {memoized_fibonacci(0)}")
        print(f"Fib(1): {memoized_fibonacci(1)}")
        print(f"Fib(10): {memoized_fibonacci(10)}")
        print(f"Fib(15): {memoized_fibonacci(15)}")

        if hasattr(memoized_fibonacci, "cache_info"):
            print("Cache Performance Diagnostics: "
                  f"{memoized_fibonacci.cache_info()}")
        else:
            print("Warning: memoized_fibonacci does not appear to "
                  "possess an active lru_cache decorator.")
    except NameError:
        print("Error: memoized_fibonacci function is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during caching sequence processing: {e}")
    print()

    print("--- 4. Testing Spell Dispatcher ---")
    try:
        cast = spell_dispatcher()

        if callable(cast):
            print(f"Damage spell (int): {cast(42)}")
            print(f"Enchantment (str): {cast('fireball')}")
            print(f"Multi-cast (list): {cast(['heal', 'shield'])}")
            print(f"Unknown type (dict): {cast({'type': 'dark'})}")
        else:
            print(
                "Error: spell_dispatcher did not return a valid "
                "dispatching function closure.")
    except NameError:
        print("Error: spell_dispatcher function is missing or not declared.")
    except Exception as e:
        print(f"An anomaly occurred during polymorphism dynamic routing: {e}")
    print()

    print("==================================================")
    print("             END OF EVALUATION MATRIX             ")
    print("==================================================")
