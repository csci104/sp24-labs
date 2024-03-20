#include "sudoku.h"
#include <iostream>

using namespace std;

Sudoku::Sudoku(int puzzle[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = puzzle[i][j];
        }
    }
}

Sudoku::~Sudoku()
{
}

void Sudoku::verify()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!isValid(i, j))
            {
                cout << "INVALID PUZZLE" << endl;
                return;
            }
        }
    }
    cout << "VALID PUZZLE" << endl;
}

void Sudoku::print()
{
    for (int row = 0; row < 9; row++)
    {
        if (row % 3 == 0)
        {
            std::cout << "-------------------------------" << std::endl;
        }

        for (int col = 0; col < 9; col++)
        {
            if (col % 3 == 0)
            {
                std::cout << "|";
            }

            if (board[row][col] != 0)
            {
                std::cout << " " << board[row][col] << " ";
            }
            else
            {
                std::cout << " . ";
            }
        }

        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
}

bool Sudoku::isValid(int row, int col)
{

    int value = board[row][col];

    for (int i = 0; i < 9; i++)
    {
        if (i == row)
        {
            continue;
        }

        int temp = board[i][col];
        if (temp == value)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (i == col)
        {
            continue;
        }

        int temp = board[row][i];
        if (temp == value)
        {
            return false;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;

    for (int i = box_row * 3; i < box_row * 3 + 3; i++)
    {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++)
        {
            if (i == row && j == col)
            {
                continue;
            }

            int temp = board[i][j];
            if (temp == value)
            {
                return false;
            }
        }
    }

    return true;
}

void Sudoku::solve()
{
    solveHelper(0, 0);
}

bool Sudoku::solveHelper(int row, int col)
{
    // TODO: IMPLEMENT THIS

    // get to after last row --> return true
    if (row == 9) {
        return true;
    }

    //if at last one of the row go to next row
    if (col == 9) {
        return solveHelper(row + 1, 0);
    }

    // check if block needs to be solved, if not move on
    if (board[row][col] != 0) {
        return solveHelper(row, col + 1);
    }

    // if block needs to be solved, try all number possibilities
    for (int num = 1; num <= 9; num++) {
        board[row][col] = num;

        // check validity
        if (isValid(row, col)){
            //if valid look @ next
            if (solveHelper(row, col + 1)) {
                return true;
            }
        }

        //else backtrack
        board[row][col] = 0;
    }

    return false;
}

// Start in the top left corner (0, 0) and work your way down
// to the bottom right corner (8, 8). At each point, check if
// the block needs to be solved. If the block’s value is 0,
// then it needs to be solved. After you have found a valid
// number to put in the block, try solving the next one in
// sequence. Continue until you have solved the puzzle or
// cannot find a number that will fit in the block.

