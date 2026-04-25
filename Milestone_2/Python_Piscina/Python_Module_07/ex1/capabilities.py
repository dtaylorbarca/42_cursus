from abc import ABC, abstractmethod
from ex0 import Creature, CreatureFactory


class HealCapability(ABC):
    @abstractmethod
    def heal(self) -> str:
        pass


class TransformCapability(ABC):
    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass


class Sproutling(Creature, HealCapability):
    def heal(self) -> str:
        return "Sproutling heals itself for a small amount"

    def attack(self) -> str:
        return "Sproutling uses Vine Whip!"


class Bloomelle(Creature, HealCapability):
    def heal(self) -> str:
        return "Bloomelle heals itself and others for a large amount"

    def attack(self) -> str:
        return "Bloomelle uses Petal Dance!"


class HealingCreatureFactory(CreatureFactory):
    def create_base(self) -> Sproutling:
        return Sproutling("Sproutling", "Grass")

    def create_evolved(self) -> Bloomelle:
        return Bloomelle("Bloomelle", "Grass/Fairy")


class Shiftling(Creature, TransformCapability):
    def __init__(self, name: str, creature_type: str):
        super().__init__(name, creature_type)
        self._is_transformed = False

    def attack(self) -> str:
        if self._is_transformed:
            return "Shiftling performas a boosted strike!"
        else:
            return "Shiftling attacks normally."

    def transform(self) -> str:
        self._is_transformed = True
        return "Shiftling shifts into a sharper form!"

    def revert(self) -> str:
        self._is_transformed = False
        return "Shiftling returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self, name: str, creature_type: str):
        super().__init__(name, creature_type)
        self._is_transformed = False

    def attack(self) -> str:
        if self._is_transformed:
            return "Morphagon unleashes a devastating morph strike!"
        else:
            return "Morphagon attacks normally."

    def transform(self) -> str:
        self._is_transformed = True
        return "Morphagon moprhs into a dragonic battle form!"

    def revert(self) -> str:
        self._is_transformed = False
        return "Morphagon stabilizes its form."


class TransformCreatureFactory(CreatureFactory):
    def create_base(self) -> Shiftling:
        return Shiftling("Shiftling", "Normal")

    def create_evolved(self) -> Morphagon:
        return Morphagon("Morphagon", "Normal/Dragon")
