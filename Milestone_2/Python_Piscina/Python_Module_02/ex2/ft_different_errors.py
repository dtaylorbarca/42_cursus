def garden_operations(operation_number: int) -> None:
    if (operation_number == 0):
        int("abc")
    elif (operation_number == 1):
        1 / 0
    elif (operation_number == 2):
        open("/non/existent/file")
    elif (operation_number == 3):
        "25" + 3
    else:
        return


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    for op in range(4):
        print(f"Testing operation {op}...")
        try:
            garden_operations(op)
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")
    print("Testing operation 4...")
    try:
        garden_operations(4)
        print("Operation completed successfully")
    except Exception as e:
        print(f"Unexpected error: {e}")
    try:
        garden_operations(0)
        garden_operations(1)
    except (ValueError, ZeroDivisionError):
        pass
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
