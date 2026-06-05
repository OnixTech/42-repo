def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)

    if temp > 40:
        raise ValueError(f"{temp} is too hot for plants (max 40°C)")
    elif temp < 0:
        raise ValueError(f"{temp} is too cold for plants (min 0°C)")
    else:
        return temp


def test_temperature() -> None:
    print("=== Garden Temperature ===")

    try:
        data = "25"
        print(f"\nInput is '{data}'")
        nbr = input_temperature(data)
        print(f"Temperature is now {nbr}°C")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    try:
        data = "abc"
        print(f"\nInput is '{data}'")
        nbr = input_temperature(data)
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    try:
        data = "100"
        print(f"\nInput is '{data}'")
        nbr = input_temperature(data)
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    try:
        data = "-50"
        print(f"\nInput is '{data}'")
        nbr = input_temperature(data)
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    print("\nAll tests completed - program didn't crush!")


if __name__ == "__main__":
    test_temperature()
