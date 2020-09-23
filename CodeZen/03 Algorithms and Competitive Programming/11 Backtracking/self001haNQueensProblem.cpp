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
    cout << "\n";
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

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == true)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == true)
        {
            return false;
        }
    }
    return true;
}

void placeNQueensHelper(vector<vector<bool>> board, int level)
{
    // printSolution(board);

    // if (level < 0)
    //     return;

    // if (prev_row >= board.size() || prev_col > board[prev_row].size())
    //     return;

    if (level >= board.size())
    {
        printSolution(board);
        return;
    }

    // bool placedThisLevel = false;
    for (int j = 0; j < board[level].size(); j++)
    {
        if (canPlaceQueen(board, level, j))
        {
            board[level][j] = true;
            // placedThisLevel = true;

            // prev_row = level;
            // prev_col = j;
            placeNQueensHelper(board, level + 1);

            board[level][j] = false;
        }
    }

    // if (placedThisLevel == true)
    //     placeNQueensHelper(board, level + 1, prev_row, prev_col);
    // else
    // {
    //     board[prev_row][prev_col] = false;
    //     placeNQueensHelper(board, level - 1, prev_row, prev_col + 1);
    // }
    return;
}

void placeNQueens(int n)
{

    if (n <= 3)
        return;

    bool default_value = false;
    vector<vector<bool>> board;
    board.resize(n, vector<bool>(n, default_value));

    placeNQueensHelper(board, 0);
}