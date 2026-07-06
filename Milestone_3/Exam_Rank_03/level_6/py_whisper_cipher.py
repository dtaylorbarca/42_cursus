"""
Write a function that creates a Caesar cipher by shifting letters in a
string by a given amount.
Non-alphabetic characters should remain unchanged.
The shift can be negative (shift left).
"""


def whisper_cipher(text: str, shift: int) -> str:
    shifted = ""
    for c in text:
        base = ord("a") if c.islower() else ord("A")
        if c.isalpha():
            shifted += chr((ord(c) + (shift % 26) - base) % 26 + base)
        else:
            shifted += c
    return shifted
