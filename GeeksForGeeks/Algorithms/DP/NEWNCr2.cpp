// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
    typedef long long int lli;
    static const int MOD = 1000000007;

    lli nCr(int n, int r)
    {
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(r + 1, -1));

        // dp[1][1] = 1;
        // dp[1][0] = 1;
        // dp[0][1] = 0;

        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
            dp[i][1] = i;
        }

        for (int j = 0; j < r + 1; j++)
        {
            dp[0][j] = 0;
            if (j != 1)
                dp[1][j] = 0;
            else
                dp[1][1] = 1;
        }

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 2; j < r + 1; j++)
            {
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends
