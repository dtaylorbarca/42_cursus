"""
Write a function that rotates an array to the right by k positions, rotating
right by k means the last k elements move to the front
"""


def twist_sequence(arr: list[int], k: int) -> list[int]:
    if not arr or not k:
        return arr
    rotate = len(arr) - (k % len(arr))
    for _ in range(rotate):
        arr.append(arr.pop(0))
    return arr


if __name__ == "__main__":
    print(True if [4, 5, 1, 2, 3] == twist_sequence([1, 2, 3, 4, 5], 2) else
          twist_sequence([1, 2, 3, 4, 5], 2))
    print(True if [3, 1, 2] == twist_sequence([1, 2, 3], 1) else
          twist_sequence([1, 2, 3], 1))
    print(True if [1, 2, 3, 4] == twist_sequence([1, 2, 3, 4], 0) else
          twist_sequence([1, 2, 3, 4], 0))
    print(True if [2, 3, 1] == twist_sequence([1, 2, 3], 5) else
          twist_sequence([1, 2, 3], 5))
    print(True if [] == twist_sequence([], 3) else twist_sequence([], 3))
