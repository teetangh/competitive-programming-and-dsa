// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int proper_bracket_expressions(int current_index, int opened, int closed, const int n, int *opening_braces, vector<vector<int>> &dp)
{
    // cout << "n " << n << endl;
    cout << "opened " << opened << "closed" << closed << endl;

    if (opened > n || closed > n)
        return 0;

    if (opened == n && closed == n)
        return dp[opened][closed] = 1;

    if (dp[opened][closed] != -1)
        return dp[opened][closed];

    if (opened == closed || opening_braces[current_index] == 1)
        return dp[opened][closed] = proper_bracket_expressions(current_index + 1, opened + 1, closed, n, opening_braces, dp);
    else if (opened == n)
        return dp[opened][closed] = proper_bracket_expressions(current_index + 1, opened, closed + 1, n, opening_braces, dp);
    else
        return dp[opened][closed] = proper_bracket_expressions(current_index + 1, opened + 1, closed, n, opening_braces, dp) + proper_bracket_expressions(current_index + 1, opened, closed + 1, n, opening_braces, dp);
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

    int n, k;

    while (tc--)
    {
        cin >> n >> k;
        // vector<int> opening_braces(k, 0);
        int *opening_braces = new int[k + 1];

        for (int i = 0; i < k; i++)
            opening_braces[i] = false;

        int open_index;
        for (int i = 0; i < k; i++)
        {
            cin >> open_index;
            opening_braces[open_index] = 1;
        }

        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(n + 1, -1));

        cout << endl;
        cout << proper_bracket_expressions(1, 0, 0, n, opening_braces, dp) << endl;

        for (auto &ele : dp)
        {
            for (auto &elem : ele)
                cout << elem << " ";
            cout << endl;
        }

        dp.clear();
        // delete[] opening_braces;
    }
    return 0;
}
