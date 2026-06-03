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


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    enchant_1 = partial(base_enchantment, power=50, element="fire")
    enchant_2 = partial(base_enchantment, power=50, element="ice")
    enchant_3 = partial(base_enchantment, power=50, element="lightning")
    return {
        "fire": enchant_1,

        "ice": enchant_2,
        "lightning": enchant_3
    }

@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    index
    index += 1

@lru_cache
def fibonacci

def spell_disbatcher() -> Callable[[Any], str]
