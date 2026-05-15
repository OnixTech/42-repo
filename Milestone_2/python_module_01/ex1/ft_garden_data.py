class Plant:
    def __init__(self: "Plant", name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self: "Plant") -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


def main() -> None:
    print("=== Garden Plant Registry ===")

    plant1 = Plant("Tomato", 15, 27)
    plant2 = Plant("Albaca", 136, 130)
    plant3 = Plant("Chupapimunino", 10, 76)

    plant1.show()
    plant2.show()
    plant3.show()


if __name__ == "__main__":
    main()
