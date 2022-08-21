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
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ulli solve(ulli n, ulli m)
{
    if (n == 1 && m == 1)
        return 0;
    if (n == 1)
        return m;
    if (m == 1)
        return n;

    if (n <= m)
        swap(n, m);

    return (n + 2 * (m - 1));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    while (tc--)
    {
        ulli n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }

    return 0;
}
