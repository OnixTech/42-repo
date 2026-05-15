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


class Flower(Plant):
    def __init__(self: "Flower", name: str, height: float,
                 age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self._bloomed = False

    def bloom(self: "Flower") -> None:
        self._bloomed = True

    def show(self: "Flower") -> None:
        super().show()
        print(f"Color: {self.color}")

        if self._bloomed:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")


class Tree(Plant):
    def __init__(
        self: "Tree",
        name: str,
        height: float,
        age: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self: "Tree") -> None:
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self.get_height()}cm long and "
            f"{self.trunk_diameter}cm wide."
        )

    def show(self: "Tree") -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter}cm")


class Vegetable(Plant):
    def __init__(self: "Vegetable", name: str, height: float, age: int,
                 harvest_season: str) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def show(self: "Vegetable") -> None:
        super().show()
        print(f"Harvest season: {self.harvest_season}")
        print(f"Nutritional_value: {self.nutritional_value}")


def main() -> None:
    flower = Flower("Rose", 35, 67, "Red")
    tree = Tree("Roble", 300, 400, 58.5)
    vegetable = Vegetable("Brocoli", 20, 45, "October")

    print("=== Garden plant Types ===")

    print("\n=== Flower")
    flower.show()
    print("[Asking the flower to bloom]")
    flower.bloom()
    flower.show()

    print("\n=== Tree")
    tree.show()
    print("[Asking the tree to produce shade]")
    tree.produce_shade()

    print("\n=== Vegetable")
    vegetable.show()
    print(f"Make {vegetable.name} to grow and age for 15 days")
    vegetable.set_age(60)
    vegetable.set_height(25)
    vegetable.nutritional_value = 25
    vegetable.show()


if __name__ == "__main__":
    main()
