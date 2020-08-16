#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
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
string helperFunction(vector<int> &nums)
{
    auto result = permute(nums);
    vector<bool> result_factor3(result.size());
    for (int i = 0; i < result.size(); i++)
    {
        bool factor3_this_string = false;
        for (int j = 0; j < result[i].size() - 1; j++)
        {
            for (int k = j + 1; k < result[i].size(); k++)
            {
                if (((result[i][j] + result[i][k]) % 3 == 0) && abs(j - k) == 1)
                {
                    factor3_this_string = true;
                    break;
                }
            }
            if (factor3_this_string == true)
                break;
        }
        result_factor3[i] = (factor3_this_string);
    }
    for (int i = 0; i < result_factor3.size(); i++)
    {
        if (result_factor3[i] == false)
            return "Yes";
    }
    return "No";
}
int main()
{

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int size;
        cin >> size;
        vector<int> nums(size);
        for (int i = 0; i < size; i++)
            cin >> nums[i];

        auto output = helperFunction(nums);
        cout << output << endl;
        nums.clear();
    }

    return 0;
}
