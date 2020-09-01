#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> my_vec;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            bool flag = false;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    flag = true;
                    my_vec.push_back(i);
                    my_vec.push_back(j);
                    break;
                }

                if (flag == true)
                    return my_vec;
            }
        }

        return my_vec;
    }
};