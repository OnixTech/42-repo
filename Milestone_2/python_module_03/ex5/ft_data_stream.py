import typing
import random


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    players = ["Diego", "Pablo", "Andrea", "Ruperta"]
    actions = ["run", "smoke", "grab", "sleep", "code", "swim", "eat", "drink"]

    while True:
        yield (random.choice(players), random.choice(actions))


def consume_events(events: list[tuple[str, str]]) -> typing.Generator[
    tuple[str, str], None, None]:
    while len(events) > 0:
        index = random.randrange(len(events))
        yield events.pop(index)


def main() -> None:
    print("=== Game Data Stream Processor ===")

    generator = gen_event()

    for i in range(10):
        event = next(generator)
        print(f"Event {i}: Player {event[0]} did action {event[1]}")

    list_events = []
    for i in range(10):
        list_events.append(next(generator))

    print(f"Build list of 10 events: {list_events}")

    for event in consume_events(list_events):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {list_events}")


if __name__ == "__main__":
    main()    
