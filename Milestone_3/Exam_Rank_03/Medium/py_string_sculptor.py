"""
Write a function that transforms a string by alternating the case of alphabetic
characters only. Non-alphabetic characters (spaces, digits, punctuaation) stay
as they are and do not advance the alternation counter. The first alphabetic
character should be lowercase, the second upercase, the third lowercase, and
so on
"""


def string_sculptor(text: str) -> str:
    alternate = 0
    converted = ""
    for c in text:
        if c.isalpha():
            if alternate == 0:
                converted += c.lower()
                alternate = 1
            else:
                converted += c.capitalize()
                alternate = 0
        else:
            converted += c
    return converted


if __name__ == "__main__":
    print(True if "hElLo" == string_sculptor("hello") else
          string_sculptor("hello"))
    print(True if "hElLo WoRlD" == string_sculptor("Hello World") else
          string_sculptor("Hello World"))
    print(True if "aBc123DeF" == string_sculptor("aBc123def") else
          string_sculptor("aBc123def"))
    print(True if "pYtHoN3.9!" == string_sculptor("Python3.9!") else
          string_sculptor("Python3.9!"))
    print(True if "" == string_sculptor("") else string_sculptor(""))
