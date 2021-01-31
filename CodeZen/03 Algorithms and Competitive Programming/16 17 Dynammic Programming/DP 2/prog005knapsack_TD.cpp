#include <iostream>
using namespace std;
// #include "Solution.h"

#include <bits/stdc++.h>
using namespace std;
int knapsackHelper(int *weights, int *values, int n, int maxWeight, vector<vector<int>> &dp)
{
    if (n == 0 || maxWeight == 0)
        return dp[n][maxWeight] = 0;

    if (dp[n][maxWeight] > 0)
        return dp[n][maxWeight];

    if (weights[n - 1] <= maxWeight)
        return dp[n][maxWeight] = max(values[n - 1] + knapsackHelper(weights, values, n - 1, maxWeight - weights[n - 1], dp),
                                      knapsackHelper(weights, values, n - 1, maxWeight, dp));
    else
        return dp[n][maxWeight] = knapsackHelper(weights, values, n - 1, maxWeight, dp);
}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(maxWeight + 1, -1));

    auto answer = knapsackHelper(weights, values, n, maxWeight, dp);
    // for (auto &ele : dp)
    // {
    //     for (auto &elem : ele)
    //     {
    //         cout << elem << " ";
    //     }
    //     cout << endl;
    // }

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

    cout << knapsack(weights, values, n, maxWeight);
}
