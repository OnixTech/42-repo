class Plant:
    def __init__(self: "Plant", name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self: "Plant") -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


def main() -> None:
    print("=== Plant Factory Output ===")

    plants = [
        Plant("Tomato", 15, 27),
        Plant("Albaca", 136, 130),
        Plant("Chupapimunino", 10, 76),
        Plant("Currywurst", 10, 76),
        Plant("Egg", 10, 76),
    ]

    for plant in plants:
        print("Created:", end=" ")
        plant.show()


if __name__ == "__main__":
    main()
