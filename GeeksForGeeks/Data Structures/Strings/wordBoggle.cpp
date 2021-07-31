// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    char usedChar = '#';
    vector<string> result;

    void printBoard(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool isValid(vector<vector<char>> &board, string word, int wordIndex, int i, int j)
    {
        if (i < 0 || i > board.size() - 1)
            return false;

        if (j < 0 || j > board[0].size() - 1)
            return false;

        if (board[i][j] == usedChar)
            return false;

        if (board[i][j] != word[wordIndex])
            return false;

        return true;
    }

    bool wordBoggleHelper(vector<vector<char>> &board, string currWord, int wordIndex, int i, int j)
    {
        if (wordIndex == currWord.size())
            return true;

        if (isValid(board, currWord, wordIndex, i, j))
        {
            for (int k = 0; k < 8; k++)
            {
                int newX = i + dx[k];
                int newY = j + dy[k];

                char safeChar = board[i][j];
                board[i][j] = usedChar;

                bool answer = wordBoggleHelper(board, currWord, wordIndex + 1, newX, newY);
                board[i][j] = safeChar;
                if (answer == true)
                    return true;
            }
        }

        return false;
    }

public:
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
    {
        vector<string> result;
        for (string str : dictionary)
        {
            bool found = false;
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[i].size(); j++)
                {
                    if (wordBoggleHelper(board, str, 0, i, j))
                    {
                        result.push_back(str);
                        // printBoard(board);
                        found = true;
                        break;
                    }
                }
                if (found == true)
                    break;
            }
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char>> board(R);
        for (int i = 0; i < R; i++)
        {
            board[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else
        {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++)
                cout << output[i] << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends

// // SampleIO
// 4

// 1
// CAT
// 3 3
// C A P
// A N D
// T I E

// 4
// FOR GEEKS QUIZ GO
// 3 3
// G I Z
// U E K
// Q S E

// 2
// db bcd
// 5 2
// d d
// b f
// e c
// b c
// d c

// 6
// dfd ded fd e dec df
// 4 2
// f f
// d e
// f b
// b e

// // OUTPUT
// C A P
// A N D
// T I E

// CAT
// G I Z
// U E K
// Q S E

// G I Z
// U E K
// Q S E

// GEEKS QUIZ
// d d
// b f
// e c
// b c
// d c

// d d
// b f
// e c
// b c
// d c

// bcd db
// f f
// d e
// f b
// b e

// f f
// d e
// f b
// b e

// f f
// d e
// f b
// b e

// df e fd
