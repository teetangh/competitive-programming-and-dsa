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
typedef long long int lli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n, m;
    cin >> n >> m;

    unordered_set<int> us;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[n];
    memset(dp, 0, sizeof(dp));

    dp[n - 1] = 1;
    us.insert(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        // NOT FOUND
        if (us.find(arr[i]) == us.end())
        {
            us.insert(arr[i]);
            dp[i] = dp[i + 1] + 1;
        }
        // FOUND
        else
            dp[i] = dp[i + 1];
    }

    while (m--)
    {
        int q;
        cin >> q;
        cout << dp[q - 1] << endl;
    }
}
