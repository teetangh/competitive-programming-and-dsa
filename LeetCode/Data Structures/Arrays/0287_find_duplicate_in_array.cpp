#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<int> hashMap(nums.size() + 1, 0);

        for (auto &ele : nums)
        {
            if (hashMap[ele] > 0)
                return ele;
            hashMap[ele] = 1;
        }

        return -1;
    }
};