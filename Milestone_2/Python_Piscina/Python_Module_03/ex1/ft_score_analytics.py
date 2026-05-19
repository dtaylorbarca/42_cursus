import sys


def score_cruncher() -> None:
    print("=== Player Score Analytics ===")

    lst: list = []
    for arg in sys.argv[1:]:
        try:
            lst = lst + [int(arg)]
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
    if lst == []:
        print("No scores provided. Usage: python3 ft_score_analytics.py"
              " <score1> <score2> ...")
        return

    print(f"Scores processed: {lst}")
    print(f"Total players: {len(lst) - 1}")
    print(f"Total score: {sum(lst)}")
    average: float = sum(lst) / (len(lst) - 1)
    print(f"Average score: {average:.1f}")
    print(f"High score: {max(lst)}")
    print(f"Low score: {min(lst)}")
    print(f"Score range = {max(lst) - min(lst)}")


if __name__ == "__main__":
    score_cruncher()
