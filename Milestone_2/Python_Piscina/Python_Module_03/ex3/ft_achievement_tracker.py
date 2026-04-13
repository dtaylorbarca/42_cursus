import random

achievements: list = [
    "Crafting Genius",
    "World savior",
    "Master Explorer",
    "Collector Supreme"
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


def gen_player_achievements() -> set:
    count: int = 0
    for _ in achievements:
        count += 1
    selected: list = []
    num = random.randrange(0, count)
    for x in range(num):
        pick: str = random.choice(achievements)
        if pick not in selected:
            selected = selected + [pick]
    return set(selected)


def achievement_hunter() -> None:
    print("=== Achievement Tracker System ===")

    alice: set = gen_player_achievements()
    bob: set = gen_player_achievements()
    charlie: set = gen_player_achievements()
    dylan: set = gen_player_achievements()

    print(f"\nPlayer Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Plyaer Dylan: {dylan}")

    print(f"\nAll distinct achievements: {alice.union(bob, charlie, dylan)}")

    print(f"\nCommon achievements: {alice.intersection(charlie, bob, dylan)}")

    others: set = bob.union(charlie, dylan)
    only_alice: set = alice.difference(others)
    print(f"\nOnly Alice has: {only_alice}")
    others: set = alice.union(charlie, dylan)
    only_bob: set = bob.difference(others)
    print(f"Only Bob has: {only_bob}")
    others: set = alice.union(bob, dylan)
    only_charlie: set = charlie.difference(others)
    print(f"Only Bob has: {only_charlie}")
    others: set = alice.union(charlie, bob)
    only_dylan: set = bob.difference(others)
    print(f"Only Dylan has: {only_dylan}")

    missing_alice: set = set()
    for x in achievements:
        if x not in alice:
            missing_alice = missing_alice.union({x})
    print(f"\nAlice is missing: {missing_alice}")
    missing_bob: set = set()
    for x in achievements:
        if x not in bob:
            missing_bob = missing_bob.union({x})
    print(f"Bob is missing: {missing_bob}")
    missing_charlie: set = set()
    for x in achievements:
        if x not in charlie:
            missing_charlie = missing_charlie.union({x})
    print(f"Charlie is missing: {missing_charlie}")
    missing_dylan: set = set()
    for x in achievements:
        if x not in dylan:
            missing_dylan = missing_dylan.union({x})
    print(f"Dylan is missing: {missing_dylan}")


if __name__ == "__main__":
    achievement_hunter()
