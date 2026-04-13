import sys
import typing


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    print("---\n")
    try:
        text: typing.IO = open(sys.argv[1])
        content = text.read()
        index: int = 0
        new_line: bool = True
        line_count: int = 0
        while index < len(content):
            if new_line:
                print(f"[FRAGMENT {line_count}]", end=" ")
                new_line = False
            while content[index] != "\n":
                print(f"{content[index]}", end="")
            new_line = True


        text.close()
        print("\n\n---")
        print(f"File '{sys.argv[1]}' closed.")
    except FileNotFoundError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
    except PermissionError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")


if __name__ == "__main__":
    main()
