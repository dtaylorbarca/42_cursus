"""
Write a function that sorts a list of strings according to multiple criteria:
1. Primary sort: By string length (shortest first)
2. Secondary sort: ASCII order, except letters are compared case-insensitively
(for strings of same length)
3. Tertiary sort: By number of vowels (ascending, for same length and lexically
equal)
4. Equal strings will appear in the same order as in the input list.
"""


def cryptic_sorter(strings: list[str]) -> list[str]:
    strings.sort(key=lambda x: (
        len(x),
        x.lower(),
        sum(c in "aeiouAEIOU" for c in x)
    ))
    return strings


if __name__ == "__main__":
    print(True if ["cat", "dog", "apple", "banana", "elephant"]
          == cryptic_sorter(["apple", "cat", "banana", "dog", "elephant"]) else
          cryptic_sorter(["apple", "cat", "banana", "dog", "elephant"]))
    print(True if ["aaa", "AAA", "bbb", "BBB"] == cryptic_sorter(
        ["aaa", "bbb", "AAA", "BBB"]) else cryptic_sorter(["aaa", "bbb", "AAA", "BBB"]))
    print(True if ["hi", "test", "hello", "world"] == cryptic_sorter(
        ["hello", "world", "hi", "test"]) else cryptic_sorter(["hello", "world", "hi", "test"]))
    print(True if [] == cryptic_sorter([]) else cryptic_sorter([]))
    print(True if [""] == cryptic_sorter([""]) else cryptic_sorter([""]))
