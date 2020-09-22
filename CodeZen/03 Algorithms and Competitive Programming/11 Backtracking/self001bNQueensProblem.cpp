#include <iostream>
#include <bits/stdc++.h>
// #include "Solution.h"
using namespace std;

void printSolution(vector<vector<bool>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
            cout << board[i][j] << " ";
    }
    cout << endl;
}

bool canPlaceQueen(vector<vector<bool>> board, int row, int col)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (i == row)
            continue;
        if (board[i][col] == true)
            return false;
    }
    for (int j = 0; j < board.size(); j++)
    {
        if (j == col)
            continue;
        if (board[row][j] == true)
            return false;
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (((col - j) / (row - i) != 1) && ((col - j) / (row - i) != -1))
                continue;
            if (board[i][j] == true)
                return false;
        }
    }
    return true;
}

void placeNQueensHelper(vector<vector<bool>> board, int level, int prev_row, int prev_col)
{
    if (level < 0)
        return;

    if (prev_row >= board.size() || prev_col > board[prev_row].size())
        return;

    if (level >= board.size())
    {
        printSolution(board);
        return;
    }

    bool placedThisLevel = false;
    for (int j = 0; j < board[level].size(); j++)
    {
        if (canPlaceQueen(board, level, j))
        {
            board[level][j] = true;
            placedThisLevel = true;

            prev_row = level;
            prev_col = j;
            break;
        }
    }

    if (placedThisLevel == true)
        placeNQueensHelper(board, level + 1, prev_row, prev_col);
    else
    {
        board[prev_row][prev_col] = false;
        placeNQueensHelper(board, level - 1, prev_row, prev_col + 1);
    }
}

void placeNQueens(int n)
{

    if (n <= 3)
        return;

    bool default_value = false;
    vector<vector<bool>> board;
    board.resize(n, vector<bool>(n, default_value));

    board[0][0] = true;
    placeNQueensHelper(board, 1, 0, 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    placeNQueens(n);
}
