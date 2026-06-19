import sys
import typing


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        file: typing.IO[str] = open(filename, "r")
    except OSError as err:
        print(f"Error opening file '{filename}': {err}")
        return

    try:
        print("---")
        print(file.read(), end="")
        print("---")
    finally:
        file.close()
        print(f"File '{filename}' closed.")


if __name__ == "__main__":
    main()
