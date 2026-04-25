from abc import ABC, abstractmethod
from typing import cast
from ex0 import Creature
from ex1 import TransformCapability, HealCapability


class BattleStrategy(ABC):
    @abstractmethod
    def act(self, creature: Creature) -> str:
        pass

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def act(self, creature: Creature) -> str:
        try:
            if not self.is_valid(creature):
                raise ValueError(
                    f"Invalid Creature '{creature.name.capitalize()}'"
                    " for this normal strategy")
            return creature.attack()
        except Exception as e:
            return f"Battle error, aborting tournament: {e}"

    def is_valid(self, creature: Creature) -> bool:
        return True


class AggressiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> str:
        if not self.is_valid(creature):
            raise ValueError(
                f"Invalid Creature '{creature.name.capitalize()}'"
                " for this aggressive strategy")
        transformer = cast(TransformCapability, creature)
        lines = [
            transformer.transform(),
            creature.attack(),
            transformer.revert()
        ]
        return "\n".join(lines)

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)


class DefensiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> str:
        if not self.is_valid(creature):
            raise ValueError(
                f"Invalid Creature '{creature.name.capitalize()}'"
                " for this defensive strategy")
        healer = cast(HealCapability, creature)
        lines = [
            healer.heal(),
            creature.attack()
        ]
        return "\n".join(lines)

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)
