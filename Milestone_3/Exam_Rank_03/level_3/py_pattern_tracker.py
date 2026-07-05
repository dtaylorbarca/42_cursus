"""
Write a function that counts the number of valid consecutive digit pairs
in a string. A valid pair consists of two adjacent digits where the second
digit is exactly one greater than the first.
A 9 followed by a 0 is NOT a valid pair.
"""


def pattern_tracker(text: str) -> int:
    prev = ""
    num = 0
    for c in text:
        if not c.isnumeric():
            prev = ""
            continue
        if prev and (int(prev) + 1 == int(c)):
            num += 1
        prev = c
    return num
