"""
Write a function that converts a number from one base to another.
Support bases from 2 to 36 inclusive, using digits 0-9 and letters A-Z for
values 10-35.
Return "ERROR" for invalid inputs (base, digits)
"""


def valid_letter(character: str, base: int) -> bool:
    if len(character) != 1:
        return False
    if (ord(character) - ord("A")) % 26 >= (base - 10):
        return False
    return True


def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    for c in number:
        try:
            int(c)
            if int(c) >= from_base:
                return "ERROR"
        except ValueError:
            if not valid_letter(c, from_base):
                return "ERROR"
    digits = len(number) - 1
    base_10 = 0
    for c in number:
        try:
            base_10 += int(c) * (from_base ** digits)
        except ValueError:
            base_10 += (ord(c) - ord("A")) % 26 + 10
        digits -= 1
    if to_base == 10:
        return str(digits)
    while base_10 > 0:
        
    


if __name__ == "__main__":
    print(number_base_converter("1010", 2, 10))
    print(number_base_converter("FF", 16, 10))
    print(number_base_converter("255", 10, 16))
    print(number_base_converter("123", 10, 2))
    print(number_base_converter("Z", 36, 10))
    print(number_base_converter("35", 10, 36))
    print(number_base_converter("123", 1, 10))
    print(number_base_converter("G", 16, 10))
