"""
Write a function that transforms a string by alternating the case of
alphabetic characters only.
Non-alphabetic characters remain unchanged and are NOT counted in the
alternation index.
The first alphabetic character should be lowercase, the second uppercase, etc.
Spaces reset the alternation (next alpha after a space is lowercase again).
"""


def string_sculptor(text: str) -> str:
    sculpted = ""
    count = 0
    for c in text:
        if c == " ":
            count = 0
            sculpted += c
            continue
        if not c.isalpha:
            sculpted += c
            continue
        if count % 2 == 0:
            sculpted += c.lower()
        else:
            sculpted += c.upper()
        count += 1
    return sculpted
