"""
Write a function that converts a number from one base to another.
Support bases from 2 to 36 inclusive.
Use digits 0-9 and letters A-Z for values 10-35.
Return "ERROR" for invalid inputs.
"""


def number_base_converter(number: str, from_base: int,
                          to_base: int) -> str:
    base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    from_digits = base[:from_base]
    to_digits = base[:to_base]
    power = 0
    intermid = 0
    result = ""
    if from_base != 10:
        for digit in number[::-1]:
            if digit not in from_digits:
                return "ERROR"
            intermid = intermid + \
                from_digits.index(digit) * (from_base ** power)
            power += 1
    else:
        intermid = int(number)
    if to_base != 10:
        while intermid > 0:
            result += to_digits[intermid % to_base]
            intermid = intermid // to_base
    else:
        return intermid
    return result


if __name__ == "__main__":
    print(number_base_converter("1010", 2, 10))
    print(number_base_converter("FF", 16, 10))
    print(number_base_converter("123", 1, 10))
