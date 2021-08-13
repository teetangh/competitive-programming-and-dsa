// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

long double solve(vector<int> nums)
{
    int size = nums.size();
    int subsetSize = 1 << size;

    long double fullSum = std::accumulate(nums.begin(), nums.end(), 0);

    long double result = INT_MIN;
    for (int subsetMask = 0; subsetMask < subsetSize; subsetMask++)
    {
        long double sum = 0;
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if ((subsetMask & (1 << i)) != 0)
            {
                sum += nums[i];
                count++;
            }
        }

        long double fa = sum / count;
        long double fb = (fullSum - sum) / (nums.size() - count);

        if (fa + fb > result)
            result = fa + fb;
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

    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << std::setprecision(12) << solve(nums) << endl;
    }
}
