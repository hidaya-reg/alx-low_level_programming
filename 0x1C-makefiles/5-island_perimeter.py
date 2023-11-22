#!/usr/bin/python3
"""Calculate the perimeter of an island described in a grid"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in grid"""
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    # Iterate through each cell in the grid
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # Check if the cell represents land
                # Check adjacent cells for water or boundary
                if i == 0 or grid[i - 1][j] != 1:  # Check cell above
                    perimeter += 1
                if j == 0 or grid[i][j - 1] != 1:  # Check cell to the left
                    perimeter += 1
                if j == cols - 1 or grid[i][j + 1] != 1:  # Check cell to the right
                    perimeter += 1
                if i == rows - 1 or grid[i + 1][j] != 1:  # Check cell below
                    perimeter += 1

    return perimeter
