#!/usr/bin/python3

"""This module contains island_perimeter() function"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid

    Args:
        grid (list): Is a list of list of integers

    """

    rectangle_width = 0
    rows = len(grid)
    columns = len(grid[0])
    for row in range(rows):
        for col in range(columns):
            if grid[row][col] == 1:
                if col == 0 or grid[row][col - 1] == 0 or col + 1 == columns\
                        or grid[row][col + 1] == 0:
                    rectangle_width += 1
                elif row + 1 == rows or grid[row + 1][col] == 0:
                    rectangle_width += 1
                else:
                    continue
    return (rectangle_width + 1) * 2
