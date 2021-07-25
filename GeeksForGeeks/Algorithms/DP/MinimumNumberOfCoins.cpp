#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    int minCoins(int coins[], int numCoins, int sum)
    {
        // Your code goes here
        vector<vector<int>> dp;
        dp.resize(numCoins + 1, vector<int>(sum + 1, -1));

        for (int i = 0; i < numCoins + 1; i++)
            dp[i][0] = 0;

        for (int j = 0; j < sum + 1; j++)
            dp[0][j] = INT_MAX - 1;

        for (int j = 1; j < sum + 1; j++)
        {
            if (j % coins[0] == 0)
                dp[1][j] = j / coins[0];
            else
                dp[1][j] = INT_MAX - 1;
        }

        for (int i = 2; i < numCoins + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[numCoins][sum] == INT_MAX - 1 ? -1 : dp[numCoins][sum];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}
// } Driver Code Ends