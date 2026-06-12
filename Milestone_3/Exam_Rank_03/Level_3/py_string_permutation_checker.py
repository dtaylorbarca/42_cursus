"""
Write a function that determins if two strings are permutations of each other.
Two strings are permutations if they contain the same characters with the same
frequencies.
"""


def string_permutation_checker(s1: str, s2: str) -> bool:
    s1_dict = {}
    for c in s1:
        try:
            s1_dict[c] += 1
        except KeyError:
            s1_dict.update({c: 1})
    s2_dict = {}
    for c in s2:
        try:
            s2_dict[c] += 1
        except KeyError:
            s2_dict.update({c: 1})
    return s1_dict == s2_dict


if __name__ == "__main__":
    print(string_permutation_checker("abc", "bca"))
    print(string_permutation_checker("abc", "def"))
    print(string_permutation_checker("listen", "silent"))
    print(string_permutation_checker("hello", "bello"))
    print(string_permutation_checker("", ""))
    print(string_permutation_checker("a", ""))
    print(string_permutation_checker("Abc", "abc"))
    print(string_permutation_checker("a gentleman", "elegant man"))
