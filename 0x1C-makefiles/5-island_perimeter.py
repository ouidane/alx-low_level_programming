#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    Args:
        grid (list): A list of list of integers representing an island.
            0 represents water, 1 represents land.

    Returns:
        int: The perimeter of the island.
    """
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0
    edges = 0
    size = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                size += 1
                if c > 0 and grid[r][c - 1] == 1:
                    edges += 1
                if r > 0 and grid[r - 1][c] == 1:
                    edges += 1

    return size * 4 - edges * 2