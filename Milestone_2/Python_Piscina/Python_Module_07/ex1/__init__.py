from abc import ABC, abstractmethod
from ..ex0 import Creature, CreatureFactory


class HealCapability(ABC):
    @abstractmethod
    def heal(self, creature: str) -> str:
        pass


class TransformCapability(ABC):
    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass


class Sproutling(Creature, HealCapability):
    def heal(self, creature: str) -> str:
        return f"{creature.capitalize()} heals itself for a small amount"

class Bloomelle(Creature, HealCapability):
    def heal(self, creature: str) -> str:
        return ""

class HealingCreatureFactory(Creature, CreatureFactory):
    

class Shiftling(Creature, TransformCapability):


class Morphagon(Creature, TransformCapability):
