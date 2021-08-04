// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1000000

bool isValid(vector<string> &chess, int x, int y, bool isDiagonal)
{
    if (x < 0 || x > 1)
        return false;

    if (y < 0 || y > chess[0].size() - 1)
        return false;

    if (chess[x][y] == '2')
        return false;

    if (!isDiagonal && chess[x][y] == '1')
        return false;

    if (isDiagonal && chess[x][y] == '0')
        return false;

    chess[x][y] = '2';

    return true;
}

int numMoves(vector<string> &chess)
{
    // auto it = find(chess[1].begin(), chess[1].end(), 1);
    // if (it == chess[1].end())
    //     return 0;

    // auto it2 = find(chess[0].begin(), chess[0].end(), 1);
    // if (it2 == chess[0].end())
    //     return count(chess[1].begin(), chess[1].end(), 1);

    int count = 0;
    for (int j = 0; j < chess[1].size(); j++)
    {
        if (chess[1][j] == '1')
        {
            count += isValid(chess, 0, j - 1, true);
            count += isValid(chess, 0, j, false);
            count += isValid(chess, 0, j + 1, true);
        }
    }

    return count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        int size;
        cin >> size;

        vector<string> chess(2);
        for (int i = 0; i < 2; i++)
            cin >> chess[i];

        cout << numMoves(chess) << endl;
    }
}
