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

// a/b = c/d
ulli solve(ulli a, ulli b, ulli c, ulli d)

{
    if (a == 0 && c == 0)
        return 0;
    else if (a == 0 || c == 0)
        return 1;

    long double x = (long double)a / b;
    long double y = (long double)c / d;
    if (x == y)
        return 0;

    long double f = (long double)(a * d) / (b * c);
    long double g = (long double)(b * d) / (a * c);
    if (abs(f - int(f)) == 0 || abs(g - int(g)) == 0)
        return 100;
    else
        return 200;
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
        ulli a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << endl;
    }

    return 0;
}
