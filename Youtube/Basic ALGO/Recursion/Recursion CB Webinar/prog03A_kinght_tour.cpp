#include <iostream>
#include <iomanip>
using namespace std;

// Board Dimensions
const int D = 8;

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

bool canPlace(int board[D][D], int n, int r, int c)
{
    return r >= 0 && r < n &&
           c >= 0 && c < n &&
           board[r][c] == 0;
}

bool solveKnightMove(int board[D][D], int n, int move_no, int curRow, int curCol)
{
    if (move_no == n * n)
        return true;

    // Defining pairwise and collectively the knight moves in row and column wise
    // Static to reduce the space complexity
    static int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    static int colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1};

    // Iterating accross all the 8 directions
    for (int curDir = 0; curDir < 8; ++curDir)
    {
        int nextRow = curRow + rowDir[curDir];
        int nextCol = curCol + colDir[curDir];

        if (canPlace(board, n, nextRow, nextCol) == true)
        {
            // Can place the knight
            board[nextRow][nextCol] = move_no + 1; //place the knight
            bool isSuccessful = solveKnightMove(board, n, move_no + 1, nextRow, nextCol);
            if (isSuccessful == true)
                return true;
            // If Fail, Reset the changes => This is the concept of BACKTRACKING
            board[nextRow][nextCol] = 0; // erase the knight's next move that was used for testing
        }
    }
    return false;
}

int main()
{
    // Setting all of them to 0
    int board[D][D] = {0};

    int n;
    cin >> n;

    // Setting the knight to (0,0)
    board[0][0] = 1;
    bool ans = solveKnightMove(board, n, 1, 0, 0);
    if (ans == true)
    {
        // my function was able to solve it
        printBoard(board, n);
    }
    else
    {
        cout << " Sorry man! Can't visit your board";
    }

    return 0;
}
// // Sample IO
// 8
//   1  60  39  34  31  18   9  64
//  38  35  32  61  10  63  30  17
//  59   2  37  40  33  28  19   8
//  36  49  42  27  62  11  16  29
//  43  58   3  50  41  24   7  20
//  48  51  46  55  26  21  12  15
//  57  44  53   4  23  14  25   6
//  52  47  56  45  54   5  22  13