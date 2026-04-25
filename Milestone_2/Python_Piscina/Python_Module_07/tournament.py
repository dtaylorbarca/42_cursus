from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    BattleStrategy,
    NormalStrategy,
    AggressiveStrategy,
    DefensiveStrategy
)


def tournament(opponents: list[tuple[CreatureFactory,
                                     BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    for i, (factory_1, strategy_1) in enumerate(opponents):
        for factory_2, strategy_2 in opponents[i + 1:]:
            print("\n* Battle *")
            opp_1 = factory_1.create_base()
            opp_2 = factory_2.create_base()
            print(opp_1.describe())
            print(" vs.")
            print(opp_2.describe())
            print(" now fight!")
            try:
                print(strategy_1.act(opp_1))
                print(strategy_2.act(opp_2))
            except ValueError as e:
                print(f"Battle error, aborting tournament: {e}")


def main() -> None:
    print("Tournamet 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")
    tournament([(FlameFactory(), NormalStrategy()),
                (HealingCreatureFactory(), DefensiveStrategy())])
    print("\nTournamet 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive)]")
    tournament([
        (FlameFactory(), AggressiveStrategy()),
        (HealingCreatureFactory(), DefensiveStrategy())
    ])
    print("\nTournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), "
          "(Transform+Aggressivev) ]")
    tournament([
        (AquaFactory(), NormalStrategy()),
        (HealingCreatureFactory(), DefensiveStrategy()),
        (TransformCreatureFactory(), AggressiveStrategy())
    ])


if __name__ == "__main__":
    main()
