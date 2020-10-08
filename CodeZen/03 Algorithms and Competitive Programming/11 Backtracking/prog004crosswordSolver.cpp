#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define N 10
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// typedefs
typedef long long ll;
typedef long long int lli;

void printSolution(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
            cout << board[i][j];
        cout << endl;
    }
}
///////////////////////////////////////////////HORIZONTAL FILLING//////////////////////////////////////////////////////////

bool isValidHorizontal(vector<vector<char>> &board, int i, int j, string checkWord)
{
    for (int x = 0; x < checkWord.size(); x++)
    {
        if (i + x >= board.size())
            return false;
        if (board[i + x][j] != '-' && board[i + x][j] != checkWord[x])
            return false;
    }
    return true;
}

void setHorizontal(vector<vector<char>> &board, int i, int j, string checkWord, vector<bool> &filledChars)
{
    for (int x = 0; x < checkWord.size(); x++)
    {
        if (board[i + x][j] == '-')
        {
            board[i + x][j] = checkWord[x];
            filledChars[x] = true;
        }
        else if (board[i + x][j] == checkWord[x])
            filledChars[x] = false;
    }
}

void resetHorizontal(vector<vector<char>> &board, int i, int j, string checkWord, vector<bool> &filledChars)
{
    for (int x = 0; x < checkWord.size(); x++)
    {
        if (filledChars[x] == true)
            board[i + x][j] = '-';
    }
}
///////////////////////////////////////////////VERTICAL FILLING//////////////////////////////////////////////////////////

bool isValidVertical(vector<vector<char>> &board, int i, int j, string checkWord)
{
    for (int y = 0; y < checkWord.size(); y++)
    {
        if (j + y >= board[i].size())
            return false;
        if (board[i][j + y] != '-' && board[i][j + y] != checkWord[y])
            return false;
    }
    return true;
}

void setVertical(vector<vector<char>> &board, int i, int j, string checkWord, vector<bool> &filledChars)
{
    for (int y = 0; y < checkWord.size(); y++)
    {
        if (board[i][j + y] == '-')
        {
            board[i][j + y] = checkWord[y];
            filledChars[y] = true;
        }
        else if (board[i][j + y] == checkWord[y])
            filledChars[y] = false;
    }
}

void resetVertical(vector<vector<char>> &board, int i, int j, string checkWord, vector<bool> &filledChars)
{
    for (int y = 0; y < checkWord.size(); y++)
    {
        if (filledChars[y] == true)
            board[i][j + y] = '-';
    }
}

///////////////////////////////////////////////SOLVING CROSSWORD//////////////////////////////////////////////////////////

bool solveCrossWord(vector<vector<char>> &board, int indexOfWord, vector<string> wordsVector)
{
    if (indexOfWord == wordsVector.size() + 1)
        return true;

    string currentWord = wordsVector[indexOfWord - 1];
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '+')
                continue;
            else
            {
                vector<bool> filledChars(currentWord.size(), false);
                if (isValidVertical(board, i, j, currentWord))
                {
                    setVertical(board, i, j, currentWord, filledChars);
                    auto answer = solveCrossWord(board, indexOfWord + 1, wordsVector);
                    if (answer)
                        return true;
                    else
                        resetVertical(board, i, j, currentWord, filledChars);
                }

                if (isValidHorizontal(board, i, j, currentWord))
                {
                    setHorizontal(board, i, j, currentWord, filledChars);
                    auto answer = solveCrossWord(board, indexOfWord + 1, wordsVector);
                    if (answer)
                        return true;
                    else
                        resetHorizontal(board, i, j, currentWord, filledChars);
                }
            }
        }
    }
    return false;
}
///////////////////////////////////////////////MAIN FUNCTION//////////////////////////////////////////////////////////

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    fastio;

    vector<vector<char>> board;
    board.resize(N, vector<char>(N, '+'));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    string allWords;
    cin >> allWords;
    vector<string> wordsVector;

    string currentWord = "";
    for (int i = 0; allWords[i] != '\0'; i++)
    {
        if (allWords[i] != ';')
            currentWord += allWords[i];
        else
        {
            wordsVector.push_back(currentWord);
            currentWord = "";
        }
    }
    wordsVector.push_back(currentWord);

    // for (auto &ele : wordsVector)
    //     cout << ele << endl;

    if (solveCrossWord(board, 1, wordsVector))
        printSolution(board);
    else
        cout << "Not possible" << endl;

    return 0;
}
