import random


ALL_ACHIEVEMENTS = ["A", "B", "C", "D", "E", "F", "G", "H", "I",
                    "J", "K"]


class Player():
    def __init__(self, name: str) -> None:
        self.name = name
        self.ach = gen_player_achievements()

    def show(self) -> None:
        print(f"Player {self.name}: {self.ach}")


def gen_player_achievements() -> set:

    achievements: set[str] = set()
    total = random.randint(5, 9)

    while len(achievements) < total:
        achievement = random.choice(ALL_ACHIEVEMENTS)
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

    print(f"\nAll distinct achievements: {a.ach.union(b.ach, c.ach, d.ach)}")
    print(f"\nCommon achievements: {a.ach.intersection(b.ach, c.ach, d.ach)}")

    print(f"\nOnly {a.name} has: {a.ach.difference(b.ach, c.ach, d.ach)}")
    print(f"Only {b.name} has: {b.ach.difference(a.ach, c.ach, d.ach)}")
    print(f"Only {c.name} has: {c.ach.difference(b.ach, a.ach, d.ach)}")
    print(f"Only {d.name} has: {d.ach.difference(b.ach, c.ach, a.ach)}")

    print(f"\n{a.name} is missing: {set(ALL_ACHIEVEMENTS).difference(a.ach)}")
    print(f"{b.name} is missing: {set(ALL_ACHIEVEMENTS).difference(b.ach)}")
    print(f"{c.name} is missing: {set(ALL_ACHIEVEMENTS).difference(c.ach)}")
    print(f"{d.name} is missing: {set(ALL_ACHIEVEMENTS).difference(d.ach)}")


if __name__ == "__main__":
    main()
