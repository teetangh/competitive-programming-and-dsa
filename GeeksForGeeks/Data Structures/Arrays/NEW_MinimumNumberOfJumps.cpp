// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
    int MAX_JUMPS = 999999;

public:
    int minJumps(int arr[], int n)
    {
        int numJumps = 0;
        int cumulativeVal = 0;
        int j;
        for (int i = 0; i < n - 1;)
        {
            int maxVal = -99999;
            int maxJ;
            int flagUpdated = 0;
            for (j = i + 1; j <= i + arr[i] && j < n; j++)
            {
                cumulativeVal = j + arr[j];
                if (cumulativeVal >= maxVal && arr[cumulativeVal] > 0)
                {
                    if (cumulativeVal >= n - 1)
                        return numJumps + 2;
                    maxVal = cumulativeVal;
                    flagUpdated = 1;
                    maxJ = j;
                }
            }

            if (flagUpdated == 0)
                return -1;
            i = maxJ;
            numJumps++;
        }
        return numJumps;
    }
    int minJumpsBruteForce(int arr[], int n)
    {
        // DP bad here try greedy
        vector<int> dp(n, MAX_JUMPS);

        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n && j <= i + arr[i]; j++)
            {
                if (dp[j] + 1 < dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
        int answer = dp[0];
        dp.clear();
        return (answer == MAX_JUMPS) ? -1 : answer;
    }
};

// { Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("xinput.txt", "r", stdin);
    // for writing output to output.txt
    freopen("xoutput.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends