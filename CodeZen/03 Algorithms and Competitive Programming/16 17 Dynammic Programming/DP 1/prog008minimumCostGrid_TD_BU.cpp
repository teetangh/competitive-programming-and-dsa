#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

int minimumCostIterative(int **input, int m, int n)
{
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
        dp[i] = new int[n];

    dp[m - 1][n - 1] = input[m - 1][n - 1];

    // Filling Last Column
    for (int i = m - 2; i >= 0; i--)
        dp[i][n - 1] = input[i][n - 1] + dp[i + 1][n - 1];

    // Filling Last Row
    for (int j = n - 2; j >= 0; j--)
        dp[m - 1][j] = input[m - 1][j] + dp[m - 1][j + 1];

    // Filling Bottom up
    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            dp[i][j] = input[i][j] + min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1]));

    // Cost from Origin
    auto answer = dp[0][0];

    for (int i = 0; i < m; i++)
        delete[] dp[i];
    delete[] dp;

    return answer;
}

int minimumCostRecursive(int **input, int si, int sj, int ei, int ej, vector<vector<int>> dp)
{
    if (si == ei && sj == ej)
        return input[ei][ej];

    if (si > ei || sj > ej)
        return INT_MAX;

    int option1 = minimumCostRecursive(input, si + 1, sj, ei, ej, dp);
    int option2 = minimumCostRecursive(input, si + 1, sj + 1, ei, ej, dp);
    int option3 = minimumCostRecursive(input, si, sj + 1, ei, ej, dp);

    return dp[ei][ej] = input[si][sj] + min(option1, min(option2, option3));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int **input = new int *[3];
    for (int i = 0; i < 3; i++)
        input[i] = new int[3];
    // input = {{4, 3, 2}, {1, 8, 3}, {3, 1, 8}};

    input[0][0] = 4;
    input[0][1] = 3;
    input[0][2] = 2;
    input[1][0] = 1;
    input[1][1] = 8;
    input[1][2] = 3;
    input[2][0] = 1;
    input[2][1] = 1;
    input[2][2] = 8;

    vector<vector<int>> dp;
    dp.resize(3, vector<int>(3, -1));

    cout << minimumCostRecursive(input, 0, 0, 2, 2, dp) << endl;
    cout << minimumCostIterative(input, 3, 3) << endl;
}
// // Output
// 14
// 14
