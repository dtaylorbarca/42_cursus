"""
Write a function that checks if the brackets in a string are valid.

A string is valid if every opening bracket has a matching closing bracket
in the correct order.

Allowed brackets: (), [], {}
"""


def bracket_validator(s: str) -> bool:
    open_brackets = ["(", "[", "{"]
    closed_brackets = [")", "]", "}"]
    processing = []
    for c in s:
        if c in open_brackets:
            processing.append(open_brackets.index(c))
        elif c in closed_brackets and processing:
            if closed_brackets.index(c) != processing.pop():
                return False
    if processing:
        return False
    return True
