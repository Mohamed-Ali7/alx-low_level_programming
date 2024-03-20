#!/usr/bin/python3

"""This module contains island_perimeter() function"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid

    Args:
        grid (list): Is a list of list of integers

    """

    rectangle_width = 0

    for int_list in grid:
        for square in int_list:
            if square == 0:
                continue

            rectangle_width += 1


    return (rectangle_width + 1) * 2
