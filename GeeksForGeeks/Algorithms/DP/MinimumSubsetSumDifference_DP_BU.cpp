// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void isSubsetSum(int N, int arr[], int sum, vector<vector<int>> &dp)
    {
        // code here

        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;

                else if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }

public:
    int minDifference(int arr[], int N)
    {

        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));
        isSubsetSum(N, arr, sum, dp);

        int currentSum = 0;
        int currentDifference = 0;

        int minimumDifference = INT_MAX;
        for (int j = 0; j < sum + 1; j++)
        {
            if (dp[N][j])
            {
                currentSum = j;
                currentDifference = abs(sum - 2 * currentSum);

                if (currentDifference < minimumDifference)
                    minimumDifference = currentDifference;
            }
        }

        return minimumDifference;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends