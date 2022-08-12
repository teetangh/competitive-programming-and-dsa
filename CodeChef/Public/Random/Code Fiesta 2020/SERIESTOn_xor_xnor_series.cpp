// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

lli max_output(lli a, lli b, lli n)
{
    vector<int> xor_dp(n);
    vector<int> xnor_dp(n);
    xor_dp.clear();
    xnor_dp.clear();

    xor_dp[0] = a, xor_dp[1] = b;
    xnor_dp[0] = a, xnor_dp[1] = b;

    for (int i = 2; i < n; i++)
        xor_dp[i] = xor_dp[i - 1] ^ xor_dp[i - 2], xnor_dp[i] = ~(xnor_dp[i - 1] ^ xnor_dp[i - 2]);

    return max(xor_dp[n - 1], xnor_dp[n - 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    while (test_cases--)
    {
        lli a, b, n;
        cin >> a >> b >> n;
        if (a <= 0 || b <= 0)
            cout << 0 << endl;
        else
            cout << max_output(a, b, n) << endl;
    }
    return 0;
}
