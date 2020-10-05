#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
// #include "solution.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli countBSTHelper(lli n, vector<lli> &dp)
{
    if (n == 0)
        return dp[n] = 1;
    if (n == 1)
        return dp[n] = 1;

    if (dp[n] > 0)
        return dp[n];

    auto MOD = 1000000007;

    auto sum = 0;
    for (lli k = 1; k <= n; k++)
        sum = (sum + ((countBSTHelper(k - 1, dp) % MOD) * (countBSTHelper(n - k, dp) % MOD))) % MOD;

    return dp[n] = sum;
}

int countBST(int n)
{
    auto MOD = 1000000007;
    vector<lli> dp(n + 1, 0);
    auto answer = countBSTHelper(n, dp);
    return answer % MOD;
}

int main()
{
    int n;
    cin >> n;
    cout << countBST(n);
    return 0;
}
