// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int row, int column, int digit)
    {

        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == digit)
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (board[i][column] == digit)
                return false;
        }

        int start_row = (row / 3) * 3;
        int start_column = (column / 3) * 3;

        for (int i = start_row; i <= start_row + 2; i++)
        {
            for (int j = start_column; j <= start_column + 2; j++)
            {
                if (board[i][j] == digit)
                    return false;
            }
        }

        return true;
    }

    bool sudokuSolver(vector<vector<char>> &board, int row, int column)
    {

        if (row == 9)
            return true;

        int next_row = row, next_column = column + 1;
        if (next_column == 9)
        {
            next_row = row + 1;
            next_column = 0;
        }

        if (board[row][column] != '.')
            return sudokuSolver(board, next_row, next_column);

        for (char digit = '1'; digit <= '9'; digit++)
        {
            if (isSafe(board, row, column, digit))
            {
                board[row][column] = digit;
                if (sudokuSolver(board, next_row, next_column))
                {
                    return true;
                };
            }
            board[row][column] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        sudokuSolver(board, 0, 0);
    }
};