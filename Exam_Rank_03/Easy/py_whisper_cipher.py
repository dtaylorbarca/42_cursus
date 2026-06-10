"""
Write a function that creates a simple cipher by shifting letters in a str by a
given amount. Non-alphabetic characters should remain unchanged
"""


def whisper_cipher(text: str, shift: int) -> str:
    cipher = ""
    for c in text:
        ascii = ord(c)
        if c.isalpha():
            base = ord("A") if c.isupper() else ord("a")
            cipher += chr((ascii - base + shift) % 26 + base)
        else:
            cipher += c
    return cipher


if __name__ == "__main__":
    print(whisper_cipher("a", 27))
    print(whisper_cipher("Hello World!", 1))
    print(whisper_cipher("xyz", 3))
    print(whisper_cipher("ABC123def", 5))
    print(whisper_cipher("", 10))
