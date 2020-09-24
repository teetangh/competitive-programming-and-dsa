#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printDP(vector<vector<int>> dp)
{
    cout << " =======================================" << endl;
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << " =======================================" << endl;
}

int minimum_health(vector<vector<int>> maze)
{
    vector<vector<int>> dp;
    dp.resize(maze.size() + 1, vector<int>(maze[0].size() + 1, 0));

    dp[maze.size()][maze[0].size()] = 1;

    for (int i = maze.size() - 1; i >= 0; i--)
    {
        printDP(dp);
        dp[i][maze[0].size()] = dp[i + 1][maze[0].size()] - maze[i][maze[0].size()];
        if (dp[i][maze[0].size()] <= 0)
            dp[i][maze[0].size()] = 1;
    }
    for (int j = maze[0].size() - 1; j >= 0; j--)
    {
        printDP(dp);
        dp[maze.size()][j] = dp[maze.size()][j + 1] - maze[maze.size()][j];
        if (dp[maze.size()][j] <= 0)
            dp[maze.size()][j] = 1;
    }

    for (int i = maze.size() - 1; i >= 0; i--)
    {
        for (int j = maze[0].size() - 1; j >= 0; j--)
        {
            dp[i][j] = maze[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            if (dp[i][j] <= 0)
                dp[i][j] = 1;
        }
    }

    int answer = dp[0][0];
    dp.clear();
    return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int rows, columns;
        cin >> rows >> columns;

        vector<vector<int>> maze;
        maze.resize(rows + 1, vector<int>(columns + 1, 0));

        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= columns; j++)
                cin >> maze[i][j];

        cout << minimum_health(maze) << endl;
        maze.clear();
    }

    return 0;
}
