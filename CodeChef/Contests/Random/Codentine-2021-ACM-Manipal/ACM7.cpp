// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef unsigned long long int ulli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    int MOD = 1000000007;
    int dp[1001];

    while (tc--)
    {
        int temp;
        cin >> temp;
        int result = 1;
        for (int i = 0; i < temp; i++)
            result = (result * 2) % MOD;

        cout << result - 1 << endl;
    }
    return 0;
}
