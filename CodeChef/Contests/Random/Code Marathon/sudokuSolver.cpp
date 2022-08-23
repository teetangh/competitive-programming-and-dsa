#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

void printSolution(vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isRowSafe(vector<vector<int>> &board, int i, int j)
{
    for (int x = 0; x < 9; x++)
    {
        if (x == i)
            continue;
        else if (board[x][j] == board[i][j])
            return false;
    }
    return true;
}

bool isColumnSafe(vector<vector<int>> &board, int i, int j)
{
    for (int y = 0; y < 9; y++)
    {
        if (y == j)
            continue;
        else if (board[i][y] == board[i][j])
            return false;
    }
    return true;
}

bool isBoxSafe(vector<vector<int>> &board, int i, int j)
{
    int boxRowStart = (i - (i % 3));
    int boxColStart = (j - (j % 3));
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (i == (boxRowStart + x) && j == (boxColStart + y))
                continue;
            else if (board[boxRowStart + x][boxColStart + y] == board[i][j])
                return false;
        }
    }
    return true;
}

bool fillPosition(vector<vector<int>> &board, int i, int j)
{
    if (!isRowSafe(board, i, j))
        return false;

    if (!isColumnSafe(board, i, j))
        return false;

    if (!isBoxSafe(board, i, j))
        return false;

    return true;
}

bool solveSudokuHelper(vector<vector<int>> &board)
{
    // cout << "============================================" << endl;
    // printSolution(board);
    // cout << "============================================" << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // cout << "i" << i << "j" << j << endl;
            if (board[i][j] == 0)
            {
                bool flagFilled = false;
                for (int k = 1; k <= 9; k++)
                {
                    // cout << "k" << k << endl;
                    board[i][j] = k;
                    bool res = fillPosition(board, i, j);
                    if (res == false)
                    {
                        board[i][j] = 0;
                        continue;
                    }
                    else
                    {
                        flagFilled = true;
                        bool answer = solveSudokuHelper(board);
                        if (answer)
                            return answer;
                        else
                        {
                            board[i][j] = 0;
                            flagFilled = false;
                            continue;
                        }
                    }
                }
                if (flagFilled == false)
                    return false;
            }
        }
    }

    return true;
}
void solveSudoku(vector<vector<int>> &board)
{
    if (solveSudokuHelper(board))
        printSolution(board);
    else
        return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    vector<vector<int>> board;
    board.resize(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    solveSudoku(board);
}

// // Sample IO
// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0

// 3 1 6 5 7 8 4 9 2 
// 5 2 9 1 3 4 7 6 8 
// 4 8 7 6 2 9 5 3 1 
// 2 6 3 4 1 5 9 8 7 
// 9 7 4 8 6 3 1 2 5 
// 8 5 1 7 9 2 6 4 3 
// 1 3 8 9 4 7 2 5 6 
// 6 9 2 3 5 1 8 7 4 
// 7 4 5 2 8 6 3 1 9 