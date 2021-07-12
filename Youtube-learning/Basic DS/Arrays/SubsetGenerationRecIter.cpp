// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

void generateSubsetsRecursiveHelper(vector<int> &nums, int idx, vector<vector<int>> &result)
{
    if (idx == nums.size() - 1)
    {
        result.push_back({});
        result.push_back({nums[idx]});
    }
    else
    {
        generateSubsetsRecursiveHelper(nums, idx + 1, result);
        int n = result.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> r = result[i];
            r.push_back(nums[idx]);
            result.push_back(r);
        }
    }
}

vector<vector<int>> generateSubsetsRecursive(vector<int> &nums)
{
    if (nums.empty())
        return {{}};
    vector<vector<int>> result;
    generateSubsetsRecursiveHelper(nums, 0, result);
    return result;
}

vector<vector<int>> generateSubsetsIterative(vector<int> &nums)
{
    if (nums.empty())
        return {{}};
    vector<vector<int>> result = {{}};

    for (int x : nums)
    {
        int n = result.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> r = result[i];
            r.push_back(x);
            result.push_back(r);
        }
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        int size;
        cin >> size;
        vector<int> nums(size);
        for (int i = 0; i < size; i++)
            cin >> nums[i];
        vector<vector<int>> result = generateSubsetsIterative(nums);

        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
                cout << result[i][j] << " ";
            cout << endl;
        }
    }
}

// // SampleIO
// 1

// 3
// 1 2 3

// // Recursive
// 3
// 2
// 3 2
// 1
// 3 1
// 2 1
// 3 2 1

// // Iterative
// 1
// 2
// 1 2
// 3
// 1 3
// 2 3
// 1 2 3
