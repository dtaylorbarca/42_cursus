"""
Write a function that determines if two strings are permutations of each other.
Case sensitive. Whitespace and punctuation count as regular characters.
Empty strings are permutations of each other.
"""


def string_permutation_checker(s1: str, s2: str) -> bool:
    s1_dict = {}
    s2_dict = {}
    for c in s1:
        s1_dict[c] = s1_dict.get(c, 0) + 1
    for c in s2:
        s2_dict[c] = s2_dict.get(c, 0) + 1
    return s1_dict == s2_dict
