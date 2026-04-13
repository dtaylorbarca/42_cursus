import random
import typing

players: list[str] = [
    "alice",
    "bob",
    "charlie",
    "dylan"
]

actions: list[str] = [
    'run',
    'eat',
    'sleep',
    'grab',
    'move',
    'climb',
    'swim',
    'use',
    'release',
    'jump',
    'attack',
    'defend',
    'craft',
    'explore',
    'trade'
]


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    while True:
        name = random.choice(players)
        action = random.choice(actions)
        yield (name, action)


def consume_event(events: list[tuple[str, str]]) -> typing.Generator[tuple[str, str], None, None]:
    while (len(events) > 0):
        index = random.randint(0, len(events) - 1)
        event = events[index]
        events[:] = events[:index] + events[index + 1:]
        yield event


def main() -> None:
    print("=== Game Data Stream Processor ===")
    gen = gen_event()
    for x in range(1000):
        event = next(gen)
        print(f"Event {x}: Player {event[0]} did action {event[1]}")
    event_gen = gen_event()
    events = [next(event_gen) for x in range(10)]
    for event in consume_event(events):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {events}")


if __name__ == "__main__":
    main()
