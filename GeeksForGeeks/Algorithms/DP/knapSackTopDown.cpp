// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int knapSackHelper(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (n == 0 || W == 0)
            return dp[n][W] = 0;

        if (dp[n][W] != -1)
            return dp[n][W];

        if (wt[n - 1] <= W)
            return dp[n][W] = max(val[n - 1] + knapSackHelper(W - wt[n - 1], wt, val, n - 1, dp),
                                  knapSackHelper(W, wt, val, n - 1, dp));
        else
            return dp[n][W] = knapSackHelper(W, wt, val, n - 1, dp);
    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(W + 1, -1));

        knapSackHelper(W, wt, val, n, dp);

        return dp[n][W];
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends

// Example 1:

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
// Example 2:

// Input:
// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
// Output: 0