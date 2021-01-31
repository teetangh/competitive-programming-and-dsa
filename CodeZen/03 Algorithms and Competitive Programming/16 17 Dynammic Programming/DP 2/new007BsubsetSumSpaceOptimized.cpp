// Includes
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool isSubsetPresent(int *val, int n, int sum)
{
    bool **dp = new bool *[2];
    for (int i = 0; i <= 1; i++)
        dp[i] = new bool[sum + 1];

    for (int j = 0; j <= sum; j++)
        dp[0][j] = false;

    dp[0][0] = true;
    int flag = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[flag][j] = dp[flag ^ 1][j];

            if (j >= val[i - 1])
                dp[flag][j] = dp[flag ^ 1][j] || dp[flag ^ 1][j - val[i - 1]];
        }

        flag ^= 1;
    }

    bool answer = dp[flag ^ 1][sum];

    // // Deallocating the DP Array
    for (int i = 0; i <= 1; i++)
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

    int n, sum;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> sum;

    if (isSubsetPresent(arr, n, sum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    delete[] arr;
}
