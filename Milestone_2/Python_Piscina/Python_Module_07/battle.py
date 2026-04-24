from ex0 import CreatureFactory, FlameFactory, AquaFactory


def create_creature(factory: CreatureFactory) -> None:
    base = factory.create_base()
    evolved = factory.create_evolved()

    print(base.describe())
    print(base.attack())
    print(evolved.describe())
    print(evolved.attack())


def creature_fight(factory_1: CreatureFactory,
                   factory_2: CreatureFactory) -> None:
    base_1 = factory_1.create_base()
    base_2 = factory_2.create_base()

    print(base_1.describe())
    print(" vs!")
    print(base_2.describe())
    print(" fight!")
    print(base_1.attack())
    print(base_2.attack())


def main() -> None:
    print("Testing factory")
    create_creature(FlameFactory())
    print("\nTesting factory")
    create_creature(AquaFactory())
    print("\nTesting battle")
    creature_fight(FlameFactory(), AquaFactory())


if __name__ == "__main__":
    main()
