// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int proper_bracket_expressions(int *opening_braces, int position, int n, int scope, vector<vector<vector<int>>> &dp)
{
    if (n == 0)
        return 1;

    if (n < 0 || scope < 0)
        return INT_MIN;

    if (dp[position][n][scope] > 0)
        return dp[position][n][scope];

    if (position == opening_braces[0]) // Have to call open brace
        return dp[position][n][scope] += proper_bracket_expressions(opening_braces + 1, position + 1, n - 1, scope + 1, dp);
    else if (position < opening_braces[0])
    {
        if (scope == 0) // Have to call open brace
            return dp[position][n][scope] += proper_bracket_expressions(opening_braces, position + 1, n - 1, scope + 1, dp);
        else // Can call both opening as well as closing brace
            return dp[position][n][scope] += proper_bracket_expressions(opening_braces, position + 1, n - 1, scope + 1, dp) + proper_bracket_expressions(opening_braces, position + 1, n, scope - 1, dp);
    }
    else
        return INT_MIN;
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
        int *opening_braces = new int[k];

        for (int i = 0; i < k; i++)
            cin >> opening_braces[i];

        vector<vector<vector<int>>> dp;
        dp.resize(2 * n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

        cout << proper_bracket_expressions(opening_braces, 1, n, 0, dp) << endl;
        dp.clear();
    }
}
