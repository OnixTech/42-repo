import math


def get_player_pos() -> tuple:
    while True:
        values = input("Enter new coordinates as floats "
                       "in format 'x,y,z': ").split(",")
        if len(values) != 3:
            print("Invalid syntax")
            continue
        try:
            x = float(values[0])
            y = float(values[1])
            z = float(values[2])
            return (x, y, z)

        except ValueError:
            print("Invalid syntax")


def get_distance(c: tuple, r: tuple) -> float:
    d = math.sqrt((c[0] - r[0])**2 + (c[1] - r[1])**2 + (c[2] - r[2])**2)
    return (round(d, 4))


def main() -> None:
    print("\nGet a first set of coordinates")
    first = get_player_pos()
    print(f"Got a first tuple: {first}")
    print(f"It includes: X={first[0]}, Y={first[1]}, Z={first[2]}")
    print(f"Distance to center: {get_distance(first, (0, 0, 0))}")

    print("\nGet a second set of coordinates")
    second = get_player_pos()
    print(f"Got a second tuple: {second}")
    print(f"It includes: X={second[0]}, Y={second[1]}, Z={second[2]}")
    print(f"Distance between the 2 sets of coordinates: "
          f"{get_distance(first, second)}")


if __name__ == "__main__":
    main()
