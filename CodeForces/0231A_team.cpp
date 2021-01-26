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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    int a, b, c;
    int count = 0;
    while (tc--)
    {
        cin >> a >> b >> c;

        if ((a == 0 && b == 0) || (b == 0 && c == 0) || (c == 0 && a == 0))
            continue;
        else
        {}
            count++;
    }

    cout << count << endl;
}
