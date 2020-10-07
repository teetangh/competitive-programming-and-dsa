#include <iostream>
using namespace std;
// #include "Solution.h"

#include <bits/stdc++.h>
using namespace std;
int knapsackHelper(int *weights, int *values, int n, int maxWeight, vector<vector<int>> &dp)
{
    if (n == 0 || maxWeight == 0)
        return dp[n][maxWeight] = 0;

    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];

    if (weights[n] <= maxWeight)
        return dp[n][maxWeight] = max(values[n] + knapsackHelper(weights, values, n - 1, maxWeight - weights[n], dp),
                                      knapsackHelper(weights, values, n - 1, maxWeight, dp));
    else
        return dp[n][maxWeight] = knapsackHelper(weights, values, n - 1, maxWeight, dp);
}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(maxWeight + 1, -1));

    return knapsackHelper(weights, values, n - 1, maxWeight, dp);
}

int main()
{

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
