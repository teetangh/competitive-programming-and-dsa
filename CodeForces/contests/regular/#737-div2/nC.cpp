// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int solve(int n, int k)
{
    int size = n;
    int subsetSize = 1 << size;

    int result = INT_MIN;
    for (int subsetMask = 0; subsetMask < subsetSize; subsetMask++)
    {
        int sum = 0;
        int count = 0;
        
        for (int i = 0; i < size; i++)
        {
            if ((subsetMask & (1 << i)) != 0)
            {
                sum += nums[i];
                count++;
            }
        }

        // int fa = sum / count;
        // int fb = (fullSum - sum) / (nums.size() - count);

        // if (fa + fb > result)
        //     result = fa + fb;
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
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
