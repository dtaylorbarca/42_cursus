import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: python3 ft_archive_creation.py <file>")
        return

    filename: str = sys.argv[1]
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")
    try:
        text: IO[str] = open(filename)
        print("---\n")
        content = text.read()
        print(content, end="")

        text.close()
        print("\n---")
        print(f"File '{filename}' closed.\n")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return

    print("Transform data:")
    print("---\n")
    lines = content.splitlines()
    transformed = "".join([f"{line}#\n" for line in lines])
    print(transformed, end="")

    print("\n---")

    new_file: str = input("Enter new file name (or empty): ")
    if not new_file:
        print("Not saving data.")
        return
    try:
        print(f"Saving data to '{new_file}'")
        temp = open(sys.argv[1], "w")
        temp.write(transformed)
        temp.close()
        print(f"Data saved in file '{new_file}'.")
    except OSError as e:
        print(f"Error opening file '{new_file}': {e}")
        print("Data not saved.")


if __name__ == "__main__":
    main()
