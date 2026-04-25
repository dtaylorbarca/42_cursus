import sys
import os


def main() -> None:
    print("MATRIX_STATUS:", end=" ")
    if sys.prefix == sys.base_prefix:
        print("You're still plugged in")
    else:
        print("Welcome to the construct")
    print(f"Current Python: {os.path.realpath(sys.executable)}")
    print("Virtual Environment:", end=" ")
    if sys.prefix == sys.base_prefix:
        print("None detected")
    else:
        print(sys.prefix)


if __name__ == "__main__":
    main()
