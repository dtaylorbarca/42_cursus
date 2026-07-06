"""
Write a function that checks if two strings are anagrams.
They must contain exactly the same letters with the same quantity,
ignoring case and spaces.
"""


def anagram(s1: str, s2: str) -> bool:
    s1_dict = {}
    s2_dict = {}
    for c in s1:
        if c == " ":
            continue
        s1_dict[c.lower()] = s1_dict.get(c.lower(), 0) + 1
    for c in s2:
        if c == " ":
            continue
        s2_dict[c.lower()] = s2_dict.get(c.lower(), 0) + 1
    return s1_dict == s2_dict
