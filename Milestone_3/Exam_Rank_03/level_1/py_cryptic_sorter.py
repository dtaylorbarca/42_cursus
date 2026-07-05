"""
Write a function that sorts a list of strings according to multiple criteria:
1. Primary sort: By string length (shortest first)
2. Secondary sort: ASCII order, except letters are compared case-insensitively
   (for strings of same length)
3. Tertiary sort: By number of vowels (ascending, for same length and
                  lexically equal)
4. Equal strings will appear in the same order as in the input list.

Forbidden functions: sorted(), list.sort()
"""


def string_length(strings: list[str]) -> list[str]:
    sorted = []
    length = len(strings)
    while len(sorted) < length:
        min_s = strings[0]
        for s in strings:
            if len(s) < len(min_s):
                min_s = s
            elif (len(s) == len(min_s) and
                  strings.index(s) != strings.index(min_s)):
                min_s = ascii_sort(min_s, s)
        sorted.append(min_s)
        strings.pop(strings.index(min_s))
    return sorted


def ascii_sort(string_1: str, string_2: str) -> str:
    s_1 = ""
    s_2 = ""
    for c in string_1:
        s_1 += c.lower()
    for c in string_2:
        s_2 += c.lower()
    if s_1 < s_2:
        return string_1
    elif s_1 == s_2:
        return vowel_sort(string_1, string_2)
    return string_2


def vowel_sort(string_1: str, string_2: str) -> list[str]:
    vowels = {"a", "e", "i", "o", "u"}
    vowels_1 = 0
    vowels_2 = 0
    for c in string_1:
        if c in vowels:
            vowels_1 += 1
    for c in string_2:
        if c in vowels:
            vowels_2 += 1
    return string_2 if vowels_2 > vowels_1 else string_1


def cryptic_sorter(strings: list[str]) -> list[str]:
    return string_length(strings)
