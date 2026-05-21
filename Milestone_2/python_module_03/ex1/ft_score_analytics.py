import sys


def score_analytics() -> None:

    lenght = len(sys.argv)
    scores = []
    i = 1
    while i < lenght:
        try:
            score = int(sys.argv[i])
            scores.append(score)
        except ValueError:
            print(f"Invalid parameter: '{sys.argv[i]}'")

        i += 1

    if len(scores) > 0:
        print(f"Scores processed: {scores}")
    else:
        print("No scores provided. Usage: python3"
              "ft_score_analytics.py <score1> <score2> ...")
        return

    lenght = len(scores)
    total = sum(scores)
    average = total / lenght
    high = max(scores)
    low = min(scores)
    range = high - low

    print(f"Total players: {lenght}")
    print(f"Total score: {total}")
    print(f"Average score: {average}")
    print(f"Hight score: {high}")
    print(f"Low score: {low}")
    print(f"Score range: {range}")


def main() -> None:
    print("=== Player Score Analytics ===")
    score_analytics()


if __name__ == "__main__":
    main()
