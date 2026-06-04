import random


def main() -> None:
    print("=== Game Data Alchemist ===")

    players = ["luciano", "Alejandro", "pablo", "Cristian"]
    print(f"Initial list of players: {players}")
    cap_only = [name for name in players if name == name.capitalize()]

    cap = [name.capitalize() for name in players]
    print(f"New list with all names capitalized: {cap}")

    print(f"New list of capitalized names only: {cap_only}")

    scores = {name: random.randint(0, 100) for name in cap}
    print(f"Score dict: {scores}")

    average = round(sum(scores.values()) / len(cap), 2)
    print(f"Score average: {average}")

    higher = {name: score for name, score in scores.items() if score > average}
    print(f"High scores: {high_scores}")

if __name__ == "__main__":
    main()
