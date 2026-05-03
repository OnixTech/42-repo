def input_temperature(temp_str) -> int:
    return int(temp_str)


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
        print(f"Temperature is now {nbr}°C")
    except ValueError as error:
        print(f"Caught input_temperature error: {error}")

    print("\nAll tests completed - program didn't crush!")
        
        


if __name__ == "__main__":
    test_temperature()
