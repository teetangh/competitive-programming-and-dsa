// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
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
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Example 1:

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 9
// Output: 1
// Explanation: Here there exists a subset with
// sum = 9, 4+3+2 = 9.
// Example 2:

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 30
// Output: 0
// Explanation: There is no subset with sum 30.