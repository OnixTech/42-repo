class Plant:
    def __init__(self: "Plant", name: str, height: float, age: int) -> None:
        self.name = name

        if height < 0:
            print(f"{name}: Error, height can't be negative")
            self._height = 0.0
        else:
            self._height = height
        if age < 0:
            print(f"{name}: Error, age can't be negative")
            self._age = 0
        else:
            self._age = age

    def set_height(self: "Plant", height: float) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height update: {height}cm")

    def set_age(self: "Plant", age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error age can't be negative")
            print("Age update rejected")
        else:
            self._age = age
            print(f"Age updated: {age} days old")

    def get_height(self: "Plant") -> float:
        return self._height

    def get_age(self: "Plant") -> int:
        return self._age

    def show(self: "Plant") -> None:
        print(f"{self.name}: {self._height}cm, {self._age} days old")


def main() -> None:
    print("=== Garden Security System ===")

    plant = Plant("Tomato", 26, 30)
    print("Plant created:", end=" ")
    plant.show()

    plant.set_height(35.8)
    plant.set_age(49)

    plant.set_height(-20.21)
    plant.set_age(-79)

    print("Current state:", end=" ")
    plant.show()


if __name__ == "__main__":
    main()
