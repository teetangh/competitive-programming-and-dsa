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
        lli n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n - 1; i++)
            cin >> vec[i];
        cout << (n * (n + 1)) / 2 - accumulate(vec.begin(), vec.end(), 0) << endl;
    }
    return 0;
}
