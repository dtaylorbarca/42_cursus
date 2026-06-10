"""
Write a function that checks if a string is a palindrome, ignoring spaces and 
case, only consider alphabetic characters for the comparions.
"""


def echo_validator(test: str) -> bool:
    const_str = "".join(c.lower() for c in test if c.isalpha())
    return bool(const_str) and const_str == const_str[::-1]


if __name__ == "__main__":
    print(echo_validator("racecar"))
    print(echo_validator("A man a plan a canal Panama"))
    print(echo_validator("race a car"))
    print(echo_validator("Was it a car or a cat I saw"))
    print(echo_validator("hello"))
    print(echo_validator("Madam Im Adam"))
    print(echo_validator(""))
