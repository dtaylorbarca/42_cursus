def input_temperature(temp_str: str) -> None:
    try:
        temp = int(temp_str)
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperatureerror: {e}")


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print("\n Input data is '25'")
    input_temperature("25")
    print("\nInput data is 'abc'")
    input_temperature("abc")
    print("\n All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
