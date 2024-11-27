#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    Args:
        grid (list of list of int): A 2D grid where 1 represents
        land and 0 represents water.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for r in range(rows):
        for c in range(cols):
            # Check if current cell is land
            if grid[r][c] == 1:
                # Check all 4 adjacent sides
                # Top side
                if r == 0 or grid[r-1][c] == 0:
                    perimeter += 1
                # Bottom side
                if r == rows-1 or grid[r+1][c] == 0:
                    perimeter += 1
                # Left side
                if c == 0 or grid[r][c-1] == 0:
                    perimeter += 1
                # Right side
                if c == cols-1 or grid[r][c+1] == 0:
                    perimeter += 1

    return perimeter