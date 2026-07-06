"""
Write a function that rotates an array to the right by k positions.
Rotating right by k means the last k elements move to the front.
"""


def twist_sequence(arr: list[int], k: int) -> list[int]:
    for _ in range(k):
        if arr:
            arr = [arr.pop()] + arr
    return arr
