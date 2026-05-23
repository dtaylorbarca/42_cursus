import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        text: IO = open(sys.argv[1], "r", encoding="utf-8")
        print("---\n")
        content = text.read()
        print(content, end="")

        text.close()
        print("---")
        print(f"File '{sys.argv[1]}' closed.")
    except PermissionError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
    except FileNotFoundError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")


if __name__ == "__main__":
    main()
