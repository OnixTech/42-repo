def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")

    elif operation_number == 1:
        10 / 0

    elif operation_number == 2:
        open("not_exist_file.txt")

    elif operation_number == 3:
        10 + "str"

    else:
        print("Operation completed successfully")


def test_error_types() -> None:
    for i in range(5):

        print(f"Testing operation {i}...")

        try:
            garden_operations(i)

        except ValueError as err:
            print(f"Caught ValueError: {err}")

        except ZeroDivisionError as err:
            print(f"Caught ZeroDivisionError: {err}")

        except FileNotFoundError as err:
            print(f"Caught FileNotFoundError: {err}")

        except TypeError as err:
            print(f"Caught TypeError: {err}")

    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
