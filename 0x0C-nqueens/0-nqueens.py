#!/usr/bin/python3
"""
N queens puzzle challenge
"""
import sys


def printBoard(board):
    """
    Function that print the coordinates row and column for the position of
    each N queen in the posible solution
    Arguments:
     - board list of list (matrix[n][n])
    """

    solve = []
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 1:
                solve.append([i, j])
    print(solve)


def isSafe(board, row, col, n):
    """
    Helper function for checking if a queen can be placed on board
    Arguments:
     - board list of list
     - row position r to check
     - col position c to check
     - n number of queens to placed
    Return:
     True or False
        - True if the queen coulb be placed
        - False if there is not a save place
    """

    for c in range(col):
        if board[row][c] == 1:
            return False

    for r, c in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if board[r][c] == 1:
            return False

    for r, c in zip(range(row, n, 1),
                    range(col, -1, -1)):
        if board[r][c] == 1:
            return False

    return True


def findSolution(board, col, n):
    """
    Helper function to solve the n queen problem using Backtracking
    fins the posibles board to placed all the n queens on it
    in a save places
    Arguments:
     - board list of list, of size board[n][n]
        * n number of queens
     - col columns to check starting on 0 until n to placed
     - n number of queens to be placed
    Returns:
     True or False
     - True if all the queens are placed on the board
     - False if a queen can not be placed
    """

    if col == n:
        printBoard(board)
        return True

    c = False
    for i in range(n):
        if isSafe(board, i, col, n):
            board[i][col] = 1
            c = findSolution(board, col + 1, n) or c
            board[i][col] = 0
    return c


if __name__ == "__main__":
    """
    Starting the program
    Take the argumetns from the command line of the form:
        - nqueens N, where N is the nmbr of queens to be placed
    """
    if not len(sys.argv) == 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not (sys.argv[1]).isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [[0 for i in range(n)] for j in range(n)]
    findSolution(board, 0, n)