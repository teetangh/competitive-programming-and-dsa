// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    bool isSubsetSum(int N, int arr[], int sum)
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));

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

        int answer = dp[N][sum];
        dp.clear();
        return answer;
    }

public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        if (sum % 2 != 0)
            return false;
        else
        {
            int target = (sum / 2);
            return isSubsetSum(N, arr, target);
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends