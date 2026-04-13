def input_temperature(temp_str: str) -> None:
    try:
        temp = int(temp_str)
        if temp > 40:
            raise ValueError(f"{temp}°C is too hot for plants (max 40°C)")
        elif temp < 0:
            raise ValueError(f"{temp}°C is too cold for plants (min 0°C)")
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print("\n Input data is '25'")
    input_temperature("25")
    print("\nInput data is 'abc'")
    input_temperature("abc")
    print("\nInput data is '100'")
    input_temperature("100")
    print("\nInput data is '-50'")
    input_temperature("-50")
    print("\n All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
