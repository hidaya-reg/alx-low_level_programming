#!/usr/bin/python3
def island_perimeter(grid):
    rows = len(grid)
    cols = len(grid[0])
    per_cell = 0
    perimeter = 0
    i = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                i+=1
                print(f'cell {i}: column {c}, row {r}')
                per_cell = 4
                if r > 0 and grid[r - 1][c] == 1:
                    per_cell -= 1
                if r < rows and grid[r + 1][c] == 1:
                    per_cell -= 1
                if c < cols and grid[r][c + 1] == 1:
                    per_cell -= 1
                if c > 0 and grid[r][c - 1] == 1:
                    per_cell -= 1
                print(per_cell)
                perimeter += per_cell
        
    return perimeter
