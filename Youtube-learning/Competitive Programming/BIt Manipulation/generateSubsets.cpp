// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<vector<int>> generateSubsets(vector<int> &nums)
{
    int size = nums.size();
    int subsetNum = (1 << size);

    vector<vector<int>> allSubsets;

    for (int subsetMask = 0; subsetMask < subsetNum; subsetMask++)
    {
        vector<int> subset;
        for (int i = 0; i < size; i++)
        {
            if ((subsetMask & (1 << i)) != 0)
                subset.push_back(nums[i]);
        }
        allSubsets.push_back(subset);
    }

    return allSubsets;
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

    while (tc--)
    {
        int size;
        cin >> size;

        vector<int> nums(size);
        for (int i = 0; i < size; i++)
            cin >> nums[i];

        auto result = generateSubsets(nums);
        for (auto subset : result)
        {
            for (auto ele : subset)
                cout << ele << " ";
            cout << endl;
        }
    }
}

// Sample IO
// 1

// 3
// 46 23 57

// 46
// 23
// 46 23
// 57
// 46 57
// 23 57
// 46 23 57
