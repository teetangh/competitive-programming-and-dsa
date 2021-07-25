// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    long long int dp[1000000 + 1];

public:
    int nthStair(int n)
    {
        //  Code here
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 2] + 1;

        return dp[n];

        //  return nthStairHelper(n,2);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends