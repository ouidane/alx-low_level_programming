#!/usr/bin/python3
"""Defines island perimeter to calculate the perimeter of an island."""


def island_perimeter(grid):
    """Calculate the perimeter of an island in a grid.

    Args:
        grid (list): A list of list of integers representing an island.
            0 represents water, 1 represents land.

    Returns:
        int: The perimeter of the island.
    """
    cols = len(grid[0]) if rows > 0 else 0
    rows = len(grid)
    edges = 0
    size = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
    return size * 4 - edges * 2
