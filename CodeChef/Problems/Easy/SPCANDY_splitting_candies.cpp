#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

typedef long long int lli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    lli test_cases;
    cin >> test_cases;
    // cout << test_cases;

    lli candies, children;
    while (test_cases--)
    {
        cin >> candies >> children;
        if (children == 0)
            cout << 0 << " " << candies << endl;
        else
            cout << candies / children << " " << candies % children << endl;
    }
    return 0;
}
