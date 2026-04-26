class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age
        self.grow_rate = height / age
    
    def grow(self) -> None:
        self.height += self.grow_rate

    def age_day(self) -> None:
        self.age += 1

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    plant = Plant("Tomato", 20, 40)
    initial_height = plant.height
    print("=== Garden plant Growth ===")
    plant.show()
    for i in range(1, 8):
        print(f"=== Day {i} ===")
        plant.grow()
        plant.age_day()
        plant.show()

    growth = round(plant.height - initial_height, 1)
    print(f"Growth this week: {growth}cm")
