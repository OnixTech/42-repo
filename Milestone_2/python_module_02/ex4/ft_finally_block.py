class PlantError(Exception):
    def __init__(self, message="Unknown plant error") -> None:
        super().__init__(message)


def water_plant(name: str) -> None:
    if name != name.capitalize():
        raise PlantError(f"Invalid plant name to water: '{name}'")

    print(f"Watering {name}: [OK]")


def main() -> None:
    print("=== Garden Watering System ===")

    try:
        print("\nTesting VALID names")
        water_plant("Carrot")
        water_plant("Lettuce")
        water_plant("Banana")

    except PlantError as er:
        print(f"Caught PlantError: {er}")
        print("... ending tests and returning to main")
        return

    finally:
        print("Closing watering system")

    
    try:
        print(f"\nTesting one INVALID (lettuce) name")
        water_plant("Carrot")
        water_plant("lettuce")
        water_plant("Banana")

    except PlantError as er:
        print(f"Caught PlantError: {er}")
        print("... ending tests and returning to main")
        return

    finally:
        print("Closing watering system")



if __name__ == "__main__":
    main()
