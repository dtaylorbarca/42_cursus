"""
Write a function that checks if a string is a palindrome,
ignoring spaces and case, only consider alphabetic characters
for the comparison.
"""


def echo_validator(text: str) -> bool:
    text_strip = ""
    for c in text:
        if not c.isalpha():
            continue
        if c.isupper():
            c = c.lower()
        text_strip += c
    return text_strip == text_strip[::-1]
