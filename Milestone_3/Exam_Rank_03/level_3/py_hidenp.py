"""
Write a function that checks if the string 'small' is a subsequence
of 'big'. A subsequence means all characters of 'small' appear in 'big'
in the same order, but not necessarily consecutively.
Function is case-sensitive.
"""


def hidenp(small: str, big: str) -> bool:
    for c in big:
        if small and c == small[0]:
            small = small[1:]
    if small:
        return False
    return True
