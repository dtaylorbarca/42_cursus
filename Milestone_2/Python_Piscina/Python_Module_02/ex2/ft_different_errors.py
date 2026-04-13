def garden_operation(operation_number: int) -> None:
    try:
        if (operation_number == 0):
            int("abc")
        elif (operation_number == 1):
            1 / 0
        elif (operation_number == 2):
            open("/non/existent/file")
        elif (operation_number == 3):
            "25" + 3
    except ValueError as e:
        print(f"Caught ValueError: {e}")
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}")
    except FileNotFoundError as e:
        print(f"Caught FileNotFoundError: {e}")
    except TypeError as e:
        print(f"Caught TypeError: {e}")
    else:
        print("Operation completed succesfully")


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    print("Testing operation 0...")
    garden_operation(0)
    print("Testing operation 1...")
    garden_operation(1)
    print("Testing operation 2...")
    garden_operation(2)
    print("Testing operation 3...")
    garden_operation(3)
    print("Testing operation 4...")
    garden_operation(4)
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
