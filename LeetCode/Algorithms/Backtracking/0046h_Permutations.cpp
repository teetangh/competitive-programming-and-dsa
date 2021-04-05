#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    if (nums.size() <= 1)
        return {nums};

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> v(nums.begin(), nums.end());
        v.erase(v.begin() + i);
        auto res = permute(v);

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
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int size;
    cin >> size;

    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];

    auto output = permute(nums);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
// // Sample IO
// 3
// 1 2 3

// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 
