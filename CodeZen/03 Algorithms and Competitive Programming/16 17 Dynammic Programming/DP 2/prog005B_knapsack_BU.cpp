#include <iostream>
using namespace std;
// #include "Solution.h"

#include <bits/stdc++.h>
using namespace std;

int knapsack(int *values, int *weights, int maxWeight, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[maxWeight + 1];

    for (int j = 0; j <= maxWeight; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (weights[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
        }
    }

    auto answer = dp[n][maxWeight];
    // Delete the dp array

    for (int i = 0; i < n; i++)
        delete[] dp[i];

    delete[] dp;

    return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(values, weights, maxWeight, n);
}
