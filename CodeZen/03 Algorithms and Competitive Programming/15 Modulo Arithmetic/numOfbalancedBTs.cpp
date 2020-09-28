#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long int lli;

lli balancedBTsHelper(int h, vector<lli> &dp)
{
    if (h == 0 || h == 1)
        return dp[h] = 1;

    if (dp[h] > 0)
        return dp[h];

    long long int MOD = 1000000007;

    long long int x = balancedBTsHelper(h - 1, dp) % MOD;
    long long int y = balancedBTsHelper(h - 2, dp) % MOD;

    return dp[h] = ((((x % MOD) * (x % MOD)) % MOD) + ((2 * (x % MOD) * (y % MOD)) % MOD)) % MOD;
}
int balancedBTs(int h)
{
    auto MOD = 1000000007;
    vector<lli> dp(h + 1, 0);
    return (balancedBTsHelper(h, dp) % MOD);
}

int main()
{
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
