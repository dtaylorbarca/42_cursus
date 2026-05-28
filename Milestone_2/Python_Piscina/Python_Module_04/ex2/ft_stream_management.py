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
        sys.stderr.write(f"[STDERR] Error opening file '{sys.argv[1]}': {e}\n")
        sys.stderr.flush()
        return

    print("Transform data:")
    print("---\n")
    lines = content.splitlines()
    transformed = "".join([f"{line}#\n" for line in lines])
    print(transformed, end="")

    print("\n---")

    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()
    new_file = sys.stdin.readline().strip()
    if not new_file:
        sys.stdout.write("Data not saved.\n")
        sys.stdout.flush()
        return
    try:
        print(f"Saving data to '{new_file}'")
        temp = open(new_file, "w")
        temp.write(transformed)
        temp.close()
        print(f"Data saved in file '{new_file}'.")
    except OSError as e:
        sys.stderr.write("[STDERR] Error opening file"
                         f" '{new_file}': {e}\n")
        sys.stderr.flush()
        sys.stdout.write("Data not saved.\n")
        sys.stdout.flush()


if __name__ == "__main__":
    main()
