import random

players: list[str] = [
    "Alice",
    "bob",
    "Charlie",
    "dylan",
    "Emma",
    "Gregory",
    "john",
    "kevin",
    "Liam"
]


def main() -> None:
    print("=== Game Data Alchemist ===\n")

    print(f"Initial list of players: {players}")
    cap_every_player: list[str] = [str.capitalize(x) for x in players]
    print(f"New list with all names capitalized: {cap_every_player}")
    all_cap_players: list[str] = [x for x in players if str.capitalize(x) == x]
    print(f"New list of capitalized names only: {all_cap_players}")

    score_dict: dict[str, int] = {x: random.randint(0, 999)
                                  for x in cap_every_player}
    print(f"\nScore dict: {score_dict}")

    score_sum: int = sum(score_dict[key] for key in score_dict)
    average: float = round(score_sum / len(score_dict), 2)
    print(f"Score average is {average}")

    high_score_dict: dict[str, int] = {key: score_dict[key]
                                       for key in score_dict
                                       if score_dict[key] > average}
    print(f"high score: {high_score_dict}")


if __name__ == "__main__":
    main()
