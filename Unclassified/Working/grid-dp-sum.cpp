// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl

int solve(vector<vector<int>> &matrix, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    dp[N - 1][N - 1] = matrix[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--)
        if (matrix[i][N - 1] == 0 || dp[i + 1][N - 1] == INT_MAX)
            dp[i][N - 1] = INT_MAX;
        else
            dp[i][N - 1] = dp[i + 1][N - 1] + matrix[i][N - 1];

    for (int j = N - 2; j >= 0; j--)
        if (matrix[N - 1][j] == 0 || dp[N - 1][j + 1] == INT_MAX)
            dp[N - 1][j] = INT_MAX;
        else
            dp[N - 1][j] = dp[N - 1][j + 1] + matrix[N - 1][j];

    for (int i = N - 2; i >= 0; i--)
        for (int j = N - 2; j >= 0; j--)
            if (matrix[i][j] == 0)
                dp[i][j] = INT_MAX;
            else if (dp[i + 1][j] == INT_MAX && dp[i][j + 1] == INT_MAX)
                dp[i][j] = INT_MAX;
            else if (dp[i + 1][j] == dp[i][j + 1])
                dp[i][j] = matrix[i][j] + dp[i + 1][j];
            else
                dp[i][j] = matrix[i][j] + min({dp[i + 1][j], dp[i][j + 1]});

    return dp[0][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, N;
    cin >> tc;

    while (tc--)
    {
        cin >> N;
        vector<vector<int>> matrix(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> matrix[i][j];

        cout << solve(matrix, N) << endl;
    }

    return 0;
}
