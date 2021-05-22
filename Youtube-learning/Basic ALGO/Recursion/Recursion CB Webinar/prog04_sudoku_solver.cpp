#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int D = 10;

void printBoard(int board[D][D], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int board[D][D], int n, int row, int col, int curNum)
{
    // If the number is already,filled can't do anything, just return
    if (board[row][col] != 0)
        return false;

    // Check the row and col
    for (int x = 0; x < n; x++)
    {
        if (board[row][x] == curNum)
            return false;
        if (board[x][col] == curNum)
            return false;
    }

    // Checking the 9 sub-matrices in the sudoku board
    int rootn = sqrt(n);
    int boxRow = row / rootn;
    int boxCol = col / rootn;
    int boxStartCellRow = boxRow * row;
    int boxStartCellCol = boxCol * rootn;

    for (int i = boxStartCellRow; i < boxStartCellRow + rootn; i++)
    {
        for (int j = boxStartCellCol; j < boxStartCellCol; j++)
        {
            if (board[i][j] != curNum)
                return false;
        }
    }

    // Has passed all the 3 conditions of non-similar numbers
    return true;
}

bool solveSudoku(int board[D][D], int n, int row, int col)
{
    if (row == n)
    {
        /* This means I have solved [0,n) rows */
        return true;
    }

    if (col == n)
    {
        /* Start with a new Row*/
        return solveSudoku(board, n, row + 1, 0);
    }

    if (board[row][col] != 0)
    {
        // In case the
        return solveSudoku(board, n, row, col + 1);
    }

    for (int curNum = 1; curNum <= n; curNum++)
    {
        if (canPlace(board, n, row, col, curNum) == true)
        {
            board[row][col] = curNum;
            // In case the current sudoku state can be solved
            bool success = solveSudoku(board, n, row, col + 1);
            if (success == true)
                return true;
            // Backtracking
            board[row][col] = 0;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int board[D][D] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };
    int n;
    cin >> n; // should be a perfect Square

    bool success = solveSudoku(board, n, 0, 0);

    if (success)
        printBoard(board, n);
    else
        cout << "Bro Solve it yourself" << endl;

    return 0;
}
// // Sample IO
// 9
//   5   3   1   2   7   6   4   9   8 
//   6   2   3   1   9   5   8   4   7 
//   1   9   8   3   4   7   5   6   2 
//   8   1   2   7   6   4   9   5   3 
//   4   7   9   8   5   3   6   2   1 
//   7   4   5   9   2   8   3   1   6 
//   9   6   7   5   3   1   2   8   4 
//   2   8   6   4   1   9   7   3   5 
//   3   5   4   6   8   2   1   7   9 