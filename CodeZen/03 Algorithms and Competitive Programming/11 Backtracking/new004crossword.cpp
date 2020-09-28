#include <bits/stdc++.h>
using namespace std;

#define N 10

void printSolution(vector<vector<char>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool isValidVertical(vector<vector<char>> &board, int i, int j, string currentWord)
{
    for (int x = 0; x < currentWord.size(); x++)
    {
        if (board[i + x][j] != '-' && board[i + x][j] != currentWord[x])
            return false;
    }

    if (board[i + currentWord.size()][j] == '-')
        return false;

    return true;
}

void setVertical(vector<vector<char>> &board, int i, int j, string currentWord)
{
}

void resetVertical(vector<vector<char>> &board, int i, int j)
{
}

bool solveCrosswordHelper(vector<vector<char>> &board, vector<pair<string, bool>> &wordsList)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == '-')
            {
                for (auto &ele : wordsList)
                {
                    if (ele.second == true)
                        continue;
                    bool flagVertical = isValidVertical(board, i, j, ele.first);
                    if (flagVertical == true)
                        setVertical(board, i, j, ele.first);
                }
            }
        }
    }

    return true;
}

void solveCrossword(vector<vector<char>> &board, vector<pair<string, bool>> &wordsList)
{
    if (solveCrosswordHelper(board, wordsList))
        printSolution(board);
    else
        return;
}

int main()
{
    vector<vector<char>> board;
    board.resize(N, vector<char>(N, '+'));

    //     for(int i = 0 ; i < N ; i++)
    //         for(int j = 0; j < N ; j++ )
    //         	cin >> board[i][j];
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            board[i][j] = s[i] - '0';
        }
    }

    string words;
    cin >> words;

    string currentWord = "";
    vector<pair<string, bool>> wordsList;

    for (int i = 0; i < words.length(); i++)
    {
        if (words[i] != ';')
            currentWord += words[i];
        else
        {
            wordsList.push_back({currentWord, false});
            currentWord.clear();
        }
    }
    return 0;
}
