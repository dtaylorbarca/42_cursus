import sys
import typing


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        text: typing.IO = open(sys.argv[1])
        print("---\n")
        content = text.read()
        index = 0
        while index < (len(content) - 1):
            while index < len(content) and content[index] != "\n":
                print(f"{content[index]}", end="")
                index += 1
            if index < len(content):
                print(f"{content[index]}", end="")
            index += 1

        text.close()
        print("\n---")
        print(f"File '{sys.argv[1]}' closed.")
    except PermissionError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
    except FileNotFoundError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")


if __name__ == "__main__":
    main()
