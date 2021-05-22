#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int matrixChainMultiplicationHelper(vector<int> &nums, int i, int j)
{
    if (i >= j)
        return 0;

    int minimumCost = INT_MAX;
    int tempAns;
    for (int k = i; k < j; k++)
    {
        tempAns = matrixChainMultiplicationHelper(nums, i, k) + matrixChainMultiplicationHelper(nums, k + 1, j) +
                  (nums[i - 1] * nums[k] * nums[j]);

        if (tempAns < minimumCost)
            minimumCost = tempAns;
    }

    return minimumCost;
}
int matrixChainMultiplication(vector<int> &nums)
{
    return matrixChainMultiplicationHelper(nums, 1, nums.size() - 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

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
