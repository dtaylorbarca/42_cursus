from collections.abc import Callable


def fireball(target: str, power: int) -> str:
    """A standard offensive fire spell."""
    return f"Fireball scorches {target} for {power} fire damage!"


def heal(target: str, power: int) -> str:
    """A restorative light spell."""
    return f"Heal restores {target} for {power} HP."


def shadow_bind(target: str, power: int) -> str:
    """A crowd-control dark spell."""
    return f"Shadow Bind immobilizes {target} for {power} seconds."


def spell_combiner(spell1: Callable[[str, int], tuple[str, str]],
                   spell2: Callable[[str, int], tuple[str, str]]
                   ) -> Callable[[str, int],
                                 tuple[tuple[str, str], tuple[str, str]]]:
    def combined_spell(target: str, power: int
                       ) -> tuple[tuple[str, str], tuple[str, str]]:
        return (spell1(target, power), spell2(target, power))
    return combined_spell


def power_amplifier(base_spell: Callable[[str, int]], multiplier: int) -> Callable:
    def amplified_power(target: str, power: int) -> Callable:
        return base_spell(target, power * multiplier)
    return amplified_power


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def casted_condition(target: str, power: int) -> Callable | str:
        if condition(target, power):
            return spell(target, power)
        else:
            return "Spell fizzled"
    return casted_condition


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequenced(target: str, power: int) -> list[str]:
        results: list[str] = []
        for spell in spells:
            results.append(spell(target, power))
        return results
    return sequenced


def main() -> None:
    target_dummy = "Dragon"

    print("--- Testing spell combiner ---")
    battle_mix = spell_combiner(fireball, heal)
    print(f"Combined spell result: {battle_mix(target_dummy, 25)}")
    print()

    print("--- Testing power amplifier ---")
    mega_fireball = power_amplifier(fireball, 3)
    print(f"Original: {fireball(target_dummy, 10)}")
    print(f"Amplified: {mega_fireball(target_dummy, 10)}")
    print()

    print("--- Testing conditional caster ---")

    boss_killer = conditional_caster(
        lambda target, power: target == "Dragon", fireball)
    print(f"Casting on Dragon: {boss_killer('Dragon', 50)}")

    fizzle_check = conditional_caster(
        lambda target, power: power < 10, fireball)
    print(
        "Casting with high power on weak condition: "
        f"{fizzle_check('Goblin', 99)}")
    print()

    print("--- Testing spell sequence ---")

    spell_combo = spell_sequence([shadow_bind, fireball, heal])
    combo_results = spell_combo(target_dummy, 15)

    print("Executing standard Mage combo:")
    for rank, result in enumerate(combo_results, 1):
        print(f"  Spell #{rank}: {result}")


if __name__ == "__main__":
    main()
