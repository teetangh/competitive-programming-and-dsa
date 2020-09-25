#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

class Solution
{

    int minScoreTriangulationHelper(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return dp[i][j] = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int minimumCost = INT_MAX;
        int tempAns;
        for (int k = i; k < j; k++)
        {
            tempAns = minScoreTriangulationHelper(nums, i, k, dp) + minScoreTriangulationHelper(nums, k + 1, j, dp) +
                      (nums[i - 1] * nums[k] * nums[j]);

            if (tempAns < minimumCost)
                minimumCost = tempAns;
        }

        return dp[i][j] = minimumCost;
    }

public:
    int minScoreTriangulation(vector<int> &nums)
    {
        vector<vector<int>> dp;
        dp.resize(nums.size() + 1, vector<int>(nums.size() + 1, -1));

        return minScoreTriangulationHelper(nums, 1, nums.size() - 1, dp);
    }
};