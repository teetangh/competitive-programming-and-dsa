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

    while (tc--)
    {
        ulli a, b, c;
        cin >> a >> b >> c;
        ulli avgAB = (a + b) / 2;
        ulli avgBC = (b + c) / 2;
        ulli avgAC = (a + c) / 2;
        if (avgAB < 35 || avgBC < 35 || avgAC < 35)
            cout << "Fail" << endl;
        else
            cout << "Pass" << endl;
    }

    return 0;
}
