// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

vector<vector<int>> generatePermutationsRecursive(vector<int> &nums)
{
    if (nums.size() <= 1)
        return {nums};

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> v(nums.begin(), nums.end());
        v.erase(v.begin() + i);
        auto res = generatePermutationsRecursive(v);

        for (int j = 0; j < res.size(); j++)
        {
            vector<int> _v = res[j];
            _v.insert(_v.begin(), nums[i]);
            result.push_back(_v);
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
        vector<vector<int>> result = generatePermutationsRecursive(nums);

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

// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 
