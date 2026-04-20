import sys
import typing


def main() -> None:
    print("=== Cyber Archives Recovery & Preservation ===")

    print(f"Accessing file '{sys.argv[1]}'")
    try:
        text: typing.IO = open(sys.argv[1])
        print("---\n")
        content = text.read()
        index: int = 0
        line_count: int = 0
        while index < (len(content) - 1):
            print("[FRAGMENT", end= " ")
            if line_count < 10:
                print("00", end="")
            elif line_count < 100:
                print("0", end="")
            print(f"{line_count}]", end=" ")
            line_count += 1
            while index < len(content) and content[index] != "\n":
                print(f"{content[index]}", end="")
                index += 1
            if index < (len(content) - 1):
                print(f"{content[index]}", end="")
                index += 1

        text.close()
        print("\n---")
        print(f"File '{sys.argv[1]}' closed.\n")
    except PermissionError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
    except FileNotFoundError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")

    print("Transform data:")
    print("---\n")
    f: typing.IO = open(sys.argv[1], "r")

    content = f.read()
    index = 0
    line_count = 0
    while index < (len(content) - 1):
        print("[FRAGMENT", end=" ")
        if line_count < 10:
            print("00", end="")
        elif line_count < 100:
            print("0", end="")
        print(f"{line_count}]", end=" ")
        line_count += 1
        while index < len(content) and content[index] != "\n":
            print(f"{content[index]}", end="")
            index += 1
        if index < (len(content) - 1):
            print(f"#{content[index]}", end="")
            index += 1
        elif index + 1 == len(content) and content[index - 1] != "\n":
            print("#")
    f.close()
    print("\n---")

    new_file: str = input("Enter new file name (or empty): ")
    if len(new_file) == 0:
        print("Not saving data.")
    else:
        print(f"Saving data to '{new_file}'")
        x = open(new_file, "w")
        temp = open(sys.argv[1], "r")
        content = temp.read()
        index = 0
        line_count = 0
        while index < (len(content) - 1):
            x.write("[FRAGMENT ")
            if line_count < 10:
                x.write("00")
            elif line_count < 100:
                x.write("0")
            x.write(f"{line_count}] ")
            line_count += 1
            while index < len(content) and content[index] != "\n":
                x.write(f"{content[index]}")
                index += 1
            if index < (len(content) - 1):
                x.write(f"#{content[index]}")
                index += 1
            elif index + 1 == len(content) and content[index - 1] != "\n":
                x.write("#")
        print(f"Data saved in file '{new_file}'.")
        x.close()
        temp.close()


if __name__ == "__main__":
    main()
