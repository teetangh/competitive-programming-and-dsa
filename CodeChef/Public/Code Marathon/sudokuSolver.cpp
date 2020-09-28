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
    cout << "============================================" << endl;
    printSolution(board);
    cout << "============================================" << endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "i" << i << "j" << j << endl;
            if (board[i][j] == 0)
            {
                bool flagFilled = false;
                for (int k = 1; k <= 9; k++)
                {
                    cout << "k" << k << endl;
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
                        break;
                    }
                }
                if (flagFilled == false)
                    return false;
                else
                {
                    bool answer = solveSudokuHelper(board);
                    if (answer)
                        return answer;
                    else
                        return false;
                }
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
