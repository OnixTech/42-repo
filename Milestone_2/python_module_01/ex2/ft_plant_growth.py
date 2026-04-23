class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        i = 1;
        grow_constant = self.height/self.age
        print("=== Garden plant Growth ===")
        print(f"{self.name}: {self.height}cm, {self.age} days old")
        while i <= 7:
            print(f"=== Day {i} ===")
            self.height += grow_constant
            print(f"{self.name}: {self.height}cm, {self.age + i} days old")
            i += 1


if __name__ == "__main__":
    plant = Plant("Tomato", 20, 40)
    plant.show() 
