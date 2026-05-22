import random

achievements: list[str] = [
    "Crafting Genius",
    "World savior",
    "Master Explorer",
    "Collector Supreme",
    "Untouchable",
    "Boss Slayer",
    "Strategist",
    "Speed Runner",
    "Survivor",
    "Treasure Hunter",
    "First Steps",
    "Sharp Mind",
    "Unstoppable",
    "Hidden Path Finder",
    "Dragon Slayer"
]


def gen_player_achievements() -> set[str]:
    num = random.randrange(1, len(achievements))
    selected = random.sample(achievements, num)
    return set(selected)


def achievement_hunter() -> None:
    print("=== Achievement Tracker System ===")

    alice: set[str] = gen_player_achievements()
    bob: set[str] = gen_player_achievements()
    charlie: set[str] = gen_player_achievements()
    dylan: set[str] = gen_player_achievements()

    print(f"\nPlayer Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")

    total_set = alice.union(bob, charlie, dylan)
    print(f"\nAll distinct achievements: {alice.union(bob, charlie, dylan)}")

    print(f"\nCommon achievements: {alice.intersection(charlie, bob, dylan)}")

    print(f"Only Alice has: {alice.difference(bob.union(charlie, dylan))}")
    print(f"Only Bob has: {bob.difference(alice.union(charlie, dylan))}")
    print(f"Only Charlie has: {charlie.difference(alice.union(bob, dylan))}")
    print(f"Only Dylan has: {dylan.difference(alice.union(bob, charlie))}")

    print(f"Alice is missing: {total_set.difference(alice)}")
    print(f"Bob is missing: {total_set.difference(bob)}")
    print(f"Charlie is missing: {total_set.difference(charlie)}")
    print(f"Dylan is missing: {total_set.difference(dylan)}")


if __name__ == "__main__":
    achievement_hunter()
