class Plant:
    class Stats:
        def __init__(self) -> None:
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        def count_age(self) -> None:
            self._age_calls += 1
    
        def count_grow(self) -> None:
            self._grow_calls += 1

        def count_show(self) -> None:
            self._show_calls += 1

        def show(self) -> None:
            print(
                f"Stats: {self._grow_calls} grow, "
                f"{self._age_calls} age, "
                f"{self._show_calls} show"
            )

    def __init__(self, name: str, height: float, age: int) -> None:
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
        self._stats = Plant.Stats()

    @staticmethod
    def is_older_than_year(age: int) -> bool:
        return age > 365

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height update: {height}cm")

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error age can't be negative")
            print("Age update rejected")
        else:
            self._age = age
            print(f"Age updated: {age} days old")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def show(self) -> None:
        self._stats.count_show()    
        print(f"{self.name}: {self._height:.1f}cm, {self._age} days old")
    
    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    def grow(self) -> None:
        self._height += 8.0
        self._stats.count_grow()

    def age(self) -> None:
        self._age += 1
        self._stats.count_age()

    def show_stats(self) -> None:
        self._stats.show()

class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self.color = color
        self._bloomed = False

    def bloom(self) -> None:
        self._bloomed = True

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")

        if self._bloomed:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")

class Tree(Plant):
    def __init__(self, name: str, height: float, age: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        self._shade_calls = 0

    def produce_shade(self) -> None:
        self._shade_calls += 1
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self.get_height()}cm long and {self.trunk_diameter}cm wide."
        )

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter}cm")

    def show_stats(self) -> None:
        super().show_stats()
        print(f"{self._shade_calls} shade")

class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self.seeds = 0

    def bloom(self) -> None:
        super().bloom()
        self.seeds = 42   # según ejemplo

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self.seeds}")

def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant.show_stats()


if __name__ == "__main__":
    print("=== Garden statistics ===")

    # --- STATIC METHOD TEST ---
    print("=== Check year-old")
    print(
        f"Is 30 days more than a year? -> "
        f"{Plant.is_older_than_year(30)}"
    )
    print(
        f"Is 400 days more than a year? -> "
        f"{Plant.is_older_than_year(400)}"
    )

    # --- FLOWER ---
    print("=== Flower")
    flower = Flower("Rose", 15.0, 10, "red")
    flower.show()
    display_statistics(flower)

    print("[asking the rose to grow and bloom]")
    flower.grow()
    flower.bloom()
    flower.show()
    display_statistics(flower)

    # --- TREE ---
    print("=== Tree")
    tree = Tree("Oak", 200.0, 365, 5.0)
    tree.show()
    display_statistics(tree)

    print("[asking the oak to produce shade]")
    tree.produce_shade()
    display_statistics(tree)

    # --- SEED ---
    print("=== Seed")
    seed = Seed("Sunflower", 80.0, 45, "yellow")
    seed.show()

    print("[make sunflower grow, age and bloom]")
    seed.grow()
    seed.age()
    seed.bloom()
    seed.show()
    display_statistics(seed)

    # --- ANONYMOUS ---
    print("=== Anonymous")
    unknown = Plant.anonymous()
    unknown.show()
    display_statistics(unknown)
