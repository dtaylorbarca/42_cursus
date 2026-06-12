"""
Write a function that checks if brackets [], parentheses (), and braces {} are
properly balanced and correctly nested in a string. All other characters are
ignored.
Return True if balanced, False otherwise
"""


def bracket_validator(s: str) -> bool:
    if not s:
        return True
    openings = ["(", "[", "{"]
    closers = [")", "]", "}"]
    processing = []
    for c in s:
        if c in openings:
            processing.append(openings.index(c))
        elif c in closers:
            if not processing or processing[-1] != closers.index(c):
                return False
            processing.pop()
    return not processing


if __name__ == "__main__":
    print(bracket_validator("()"))
    print(bracket_validator("()[]{}"))
    print(bracket_validator("(])"))
    print(bracket_validator("([)]"))
    print(bracket_validator("{[]}"))
    print(bracket_validator("hello(world)[test]{code}"))
    print(bracket_validator("((()))"))
    print(bracket_validator("((())"))
    print(bracket_validator(""))
