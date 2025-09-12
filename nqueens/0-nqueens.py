#!/usr/bin/python3
"""
Solves the N-Queens problem using a backtracking algorithm.

This program finds and prints all possible solutions for placing N
non-attacking queens on an N x N chessboard.
"""
import sys


def solve_nqueens(n):
    """
    Finds all solutions to the N-Queens problem.

    Args:
        n (int): The size of the chessboard and number of queens.

    Returns:
        list: A list of all valid solutions, where each solution is a list
              of [row, col] pairs representing queen positions.
    """
    solutions = []
    board = [-1] * n

    def is_safe(row, col):
        """
        Checks if placing a queen at (row, col) is safe from previous queens.

        Args:
            row (int): The current row.
            col (int): The current column.

        Returns:
            bool: True if the placement is safe, False otherwise.
        """
        for prev_row in range(row):
            # Check for column conflict
            if board[prev_row] == col:
                return False
            # Check for diagonal conflict
            if abs(board[prev_row] - col) == abs(prev_row - row):
                return False
        return True

    def backtrack(row):
        """
        Recursive backtracking function to find solutions.

        Args:
            row (int): The current row to place a queen on.
        """
        if row == n:
            # Base case: All queens have been placed successfully
            solution = []
            for r in range(n):
                solution.append([r, board[r]])
            solutions.append(solution)
            return

        for col in range(n):
            if is_safe(row, col):
                board[row] = col
                backtrack(row + 1)

    backtrack(0)
    return solutions


def main():
    """
    Main function to handle input validation and program execution.
    """
    # Validate number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Validate N is a number
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Validate N is at least 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Solve the problem and print solutions
    all_solutions = solve_nqueens(n)
    for solution in all_solutions:
        print(solution)


if __name__ == "__main__":
    main()
