import sys
import os
import site


def main() -> None:
    print("MATRIX_STATUS:", end=" ")
    if sys.prefix == sys.base_prefix:
        print("You're still plugged in")
        print(f"\nCurrent Python: {os.path.realpath(sys.executable)}")
        print("None detected")

        print("\nWARNING: You're in the global environment!")
        print("The machines can see everything you install.")

        print("\nTo enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env\\Scripts\\activate # On Windows")

        print("\nThen run this program again.")
    else:
        print("Welcome to the construct")
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {os.path.split(sys.prefix)[1]}")
        print(f"Environment Path: {sys.prefix}")

        print("\nSUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting")
        print("the global system.")

        print("\nPackage installation path:")
        print(site.getsitepackages()[0])


if __name__ == "__main__":
    main()
