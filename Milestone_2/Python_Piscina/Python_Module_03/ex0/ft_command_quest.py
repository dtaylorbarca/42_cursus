import sys

def command_quest() -> None:
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    i = 1
    if len(sys.argv) > 1:
        print(f"Arguments received: {len(sys.argv) - 1}")
        for arg in sys.argv[1:]:
            print(f"Argument {i}: {arg}")
            i += 1
    elif len(sys.argv) == 1:
        print("No arguments provided!")
    print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    command_quest()
