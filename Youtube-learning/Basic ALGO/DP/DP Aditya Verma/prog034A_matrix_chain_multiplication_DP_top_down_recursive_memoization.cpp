#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int matrixChainMultiplicationHelper(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return dp[i][j] = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int minimumCost = INT_MAX;
    int tempAns;
    for (int k = i; k < j; k++)
    {
        tempAns = matrixChainMultiplicationHelper(nums, i, k, dp) + matrixChainMultiplicationHelper(nums, k + 1, j, dp) +
                  (nums[i - 1] * nums[k] * nums[j]);

        if (tempAns < minimumCost)
            minimumCost = tempAns;
    }
    return dp[i][j] = minimumCost;
}
int matrixChainMultiplication(vector<int> &nums)
{
    vector<vector<int>> dp;
    dp.resize(nums.size() + 1, vector<int>(nums.size() + 1, -1));
    return matrixChainMultiplicationHelper(nums, 1, nums.size() - 1, dp);
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
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << matrixChainMultiplication(nums) << endl;
        nums.clear();
    }

    return 0;
}
// // Sample IO
// 3

// 5
// 40 20 30 10 30

// 5
// 10 20 30 40 30

// 3
// 10 20 30

// 26000
// 30000
// 6000
