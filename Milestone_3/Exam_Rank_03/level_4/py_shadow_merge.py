"""
Write a function that merges two sorted lists into one sorted list.
"""


def shadow_merge(list1: list[int], list2: list[int]) -> list[int]:
    length = len(list1) + len(list2)
    sorted = []
    for _ in range(length):
        if not list1 and list2:
            sorted.append(list2.pop(0))
        elif not list2 and list1:
            sorted.append(list1.pop(0))
        elif list1[0] < list2[0]:
            sorted.append(list1.pop(0))
        else:
            sorted.append(list2.pop(0))
    return sorted
