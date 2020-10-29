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

    lli factorial(lli x, vector<lli> &dp)
    {
        if (x == 0 || x == 1)
            return dp[x] = 1;

        if (dp[x] != -1)
            return dp[x];

        for (lli i = 2; i <= x; i++)
            dp[i] = (i * dp[i - 1]) % MOD;

        return dp[x];
    }

    lli nCr(lli n, lli r)
    {
        if (r > n)
            return 0;

        vector<lli> dp(1001, -1);
        dp[0] = dp[1] = 1;

        auto temp = (float)(factorial(n, dp) % MOD) / ((((factorial(n - r, dp) % MOD) * (factorial(r, dp) % MOD))) % MOD);

        // for (auto &ele : dp)
        //     cout << ele << " ";
        // cout << endl;

        return temp;
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
