"""
Write a function that returns a string with the characters that appear
in both strings, without repetitions. Characters are added in the order
they appear in the first string.
"""


def inter(s1: str, s2: str) -> str:
    result = ""
    for c in s1:
        if c in s2 and c not in result:
            result += c
    return result
