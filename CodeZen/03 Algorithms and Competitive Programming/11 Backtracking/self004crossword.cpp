#include <bits/stdc++.h>
using namespace std;

#define N 10

void printSolution(vector<vector<char>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j];
        cout << endl;
    }
}
///////////////////////////////////////////////////////////////// Vertical Filling//////////////////////////////////////////////////////////////////////////
bool isValidVertical(vector<vector<char>> &board, int i, int j, string currentWord)
{
    for (int x = 0; x < currentWord.size(); x++)
    {
        if (i + x >= N)
            return false;
        if (board[i + x][j] != '-' && board[i + x][j] != currentWord[x])
            return false;
    }

    return true;
}

void setVertical(vector<vector<char>> &board, int i, int j, string currentWord, vector<bool> &filledCharactersMap)
{
    for (int x = 0; x < currentWord.size(); x++)
    {
        if (board[i + x][j] != currentWord[x])
        {
            board[i + x][j] = currentWord[x];
            filledCharactersMap[x] = true;
        }
    }
}

void resetVertical(vector<vector<char>> &board, int i, int j, vector<bool> &filledCharactersMap)
{
    for (int x = 0; x < filledCharactersMap.size(); x++)
    {
        if (filledCharactersMap[i] == true)
        {
            board[i + x][j] = '-';
            filledCharactersMap[x] = false;
        }
    }
}
///////////////////////////////////////////////////////////////// Horizontal Filling//////////////////////////////////////////////////////////////////////////
bool isValidHorizontal(vector<vector<char>> &board, int i, int j, string currentWord)
{
    for (int y = 0; y < currentWord.size(); y++)
    {
        if (j + y >= N)
            return false;
        if (board[i][j + y] != '-' && board[i][j + y] != currentWord[y])
            return false;
    }

    return true;
}

void setHorizontal(vector<vector<char>> &board, int i, int j, string currentWord, vector<bool> &filledCharactersMap)
{
    for (int y = 0; y < currentWord.size(); y++)
    {
        if (board[i][j + y] != currentWord[y])
        {
            board[i][j + y] = currentWord[y];
            filledCharactersMap[y] = true;
        }
    }
}

void resetHorizontal(vector<vector<char>> &board, int i, int j, vector<bool> &filledCharactersMap)
{
    for (int y = 0; y < filledCharactersMap.size(); y++)
    {
        if (filledCharactersMap[i] == true)
        {
            board[i][j + y] = '-';
            filledCharactersMap[y] = false;
        }
    }
}
///////////////////////////////////////////////////////////////// Solving the Crossword //////////////////////////////////////////////////////////////////////////

bool solveCrosswordHelper(vector<vector<char>> &board, vector<pair<string, bool>> &wordsList)
{
    // printSolution(board);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // cout << 'i' << i << 'j' << j << endl;
            if (board[i][j] == '-' || (board[i][j] >= 'A' && board[i][j] <= 'Z'))
            {
                // cout << "entered" << board[i][j] << endl;
                bool flagFilled = false;
                for (auto &ele : wordsList)
                {
                    if (ele.second == true)
                        continue;

                    else if (isValidVertical(board, i, j, ele.first))
                    {
                        vector<bool> filledCharactersMap(ele.first.size(), false);
                        setVertical(board, i, j, ele.first, filledCharactersMap);
                        ele.second = true;
                        flagFilled = true;
                        bool answerVertical = solveCrosswordHelper(board, wordsList);
                        if (answerVertical)
                            return answerVertical;
                        else
                        {
                            resetVertical(board, i, j, filledCharactersMap);
                            ele.second = false;
                            flagFilled = false;
                        }
                    }

                    else if (isValidHorizontal(board, i, j, ele.first))
                    {
                        vector<bool> filledCharactersMap(ele.first.size(), false);
                        setHorizontal(board, i, j, ele.first, filledCharactersMap);
                        ele.second = true;
                        flagFilled = true;
                        bool answerHorizontal = solveCrosswordHelper(board, wordsList);
                        if (answerHorizontal)
                            return answerHorizontal;
                        else
                        {
                            resetHorizontal(board, i, j, filledCharactersMap);
                            ele.second = false;
                            flagFilled = false;
                        }
                    }
                }

                if (flagFilled = false)
                    return false;

                // for (auto &ele : wordsList)
                // {
                //     if (ele.second == false)
                //         return false;
                // }
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
            board[i][j] = s[j];
    }

    string words;
    cin >> words;

    string currentWord = "";
    vector<pair<string, bool>> wordsList;

    for (int i = 0; i < words.length() + 1; i++)
    {
        if (words[i] != ';' && words[i] != '\0')
            currentWord += words[i];
        else
        {
            wordsList.push_back({currentWord, false});
            currentWord.clear();
        }
    }

    solveCrossword(board, wordsList);

    return 0;
}
