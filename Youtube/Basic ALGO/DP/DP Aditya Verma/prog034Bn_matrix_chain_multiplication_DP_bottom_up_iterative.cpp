#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>> &dp)
{
    cout << "=============================" << endl;
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << setw(7) << dp[i][j];
        }
        cout << endl;
    }
    cout << "=============================" << endl;
}
int matrixChainMultiplicationHelper(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{

    for (int length = 2; length < nums.size(); length++)
    {
        for (int i = 0; i < dp.size(); i++)
        {
            int j = i + length - 1;
            // for (int j = i + 1; j < dp[0].size(); j++)
            // {
            int min_cost = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int current_cost = dp[i][k] + dp[k + 1][j] + (nums[i - 1] * nums[k] * nums[j]);
                if (current_cost < min_cost)
                    min_cost = current_cost;
            }
            dp[i][j] = min_cost;
            // }
        }
    }
    printDP(dp);
    return dp[0][dp[0].size() - 1];
}
int matrixChainMultiplication(vector<int> &nums)
{
    vector<vector<int>> dp;
    dp.resize(nums.size() + 1, vector<int>(nums.size() + 1, 0));
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
