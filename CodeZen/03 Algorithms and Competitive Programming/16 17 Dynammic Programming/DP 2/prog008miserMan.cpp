// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid;
    grid.resize(N, vector<int>(M, 0));

    auto dp(grid);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    for (int j = 0; j < M; j++)
        dp[0][j] = grid[0][j];

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j == 0)
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
            else if (j == M - 1)
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = grid[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
        }
    }

    int min_cost = INT_MAX;

    for (int j = 0; j < M; j++)
    {
        if (dp[N - 1][j] < min_cost)
            min_cost = dp[N - 1][j];
    }

    cout << min_cost << endl;
}
