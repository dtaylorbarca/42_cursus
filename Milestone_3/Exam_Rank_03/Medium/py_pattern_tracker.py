"""
Write a function that counts the number of valid consecutive digit pairs in a
string. A valid pair consists of two adjacent digits where the second digit is
exactly one greater than the first digit. A 9 followed by a 0 is NOT a valid
pair and only consider consecutive characters that are both digits (0-9)
"""


def pattern_tracker(text: str) -> int:
    consecutive = 0
    for i, c in enumerate(text):
        if c.isdigit() and c != "9" and i + 1 < len(text):
            if text[i + 1] == chr(ord(c) + 1):
                consecutive += 1
    return consecutive


if __name__ == "__main__":
    print(True if 2 == pattern_tracker("123") else pattern_tracker("123"))
    print(True if 2 == pattern_tracker("12a34") else pattern_tracker("12a34"))
    print(True if 0 == pattern_tracker("987654321") else pattern_tracker("987654321"))
    print(True if 7 == pattern_tracker("01234567") else pattern_tracker("01234567"))
    print(True if 0 == pattern_tracker("abc") else pattern_tracker("abc"))
    print(True if 0 == pattern_tracker("1a2b3c4") else pattern_tracker("1a2b3c4"))
    print(True if 2 == pattern_tracker("112233") else pattern_tracker("112233"))
