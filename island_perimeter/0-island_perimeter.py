#!/usr/bin/python3
''' Returns the perimeter of the island '''


def island_perimeter(grid):
    ''' Returns the perimeter of the island '''
    if not grid or not isinstance(grid, list):
        raise ValueError("Grid must be a list of lists")
    if not all(isinstance(row, list) for row in grid):
        raise ValueError("Grid must be a list of lists")

    rows = len(grid)
    if rows == 0:
        return 0

    cols = len(grid[0])
    if not all(len(row) == cols for row in grid):
        raise ValueError("Rows must have the same number of columns")

    perimeter = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] not in (0, 1):
                raise ValueError("Grid elements must be 0 or 1")
            if grid[r][c] == 1:
                # right
                perimeter += 1 if c == cols - 1 or grid[r][c + 1] == 0 else 0
                # left
                perimeter += 1 if c == 0 or grid[r][c - 1] == 0 else 0
                # top
                perimeter += 1 if r == 0 or grid[r - 1][c] == 0 else 0
                # bottom
                perimeter += 1 if r == rows - 1 or grid[r + 1][c] == 0 else 0

    return perimeter
