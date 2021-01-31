// Includes
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool subsetSum(int *val, int n, int sum)
{
    bool **dp = new bool *[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new bool[sum + 1];

    for (int j = 0; j <= sum; j++)
        dp[0][j] = false;

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= val[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i][j - val[i - 1]];
        }
    }

    bool answer = dp[n][sum];

    // Deallocating the DP Array
    for (int i = 0; i <= n; i++)
        delete[] dp[i];
    delete[] dp;

    return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int val[] = {1, 3, 5, 7, 9};
    int sum = 12;

    cout << subsetSum(val, 5, sum) << endl;
    return 0;
}
