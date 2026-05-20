class GardenError(Exception):
    def __init__(self, message="Unknown garden error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message="Unknown water error") -> None:
        super().__init__(message)


def test_plant_error() -> None:
    raise PlantError("The plant is drying out!")


def test_water_error(water_level: int) -> None:
    if water_level < 4:
        raise WaterError("The tank is getting empty!")


def main() -> None:
    print("=== Custom Garden Errors Demo ===")

    try:
        print("\nTesting PlantError...")
        test_plant_error()
        print("\nTesting WaterError...")
        test_water_error(3)

    except PlantError as er:
        print(f"Caught PlantError: {er}")

    try:
        test_water_error(3)

    except WaterError as er:
        print(f"Caught WaterError: {er}")

    print("\nTesting catching all garden errors...")
    try:
        test_plant_error()

    except GardenError as er:
        print(f"Caught GardenError: {er}")

    try:
        test_water_error(2)

    except GardenError as er:
        print(f"Caught GardenError: {er}")

    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    main()
