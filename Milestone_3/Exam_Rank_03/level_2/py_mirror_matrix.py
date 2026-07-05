"""
Given a 2D matrix (list of lists), return a new matrix where each row
is reversed.
"""


def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
    return [row[::-1] for row in matrix]
