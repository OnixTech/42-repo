import random


class Player():
    def __init__(self, name: str) -> None:
        self.name = name
        self.ach = gen_player_achievements()

    def show(self) -> None:
        print(f"Player {self.name}: {self.ach}") 


def gen_player_achievements() -> set:

    all_achievements = ["A", "B", "C", "D", "E", "F", "G", "H", "I",
    "J", "K"]

    achievements = set()
    total = random.randint(5, 9)
    
    while len(achievements) < total:
        achievement = random.choice(all_achievements)
        achievements.add(achievement)

    return achievements


def main() -> None:
    print("=== Achievement Tracker System ===\n")
    
    a = Player("Miguel")
    a.show()
    b = Player("Diego")
    b.show()
    c = Player("Pablo")
    c.show()
    d = Player("Angelina")
    d.show()

    print(f"All distinct achievements: {a.ach.union(b.ach, c.ach, d.ach)}")


if __name__ == "__main__":
    main()
