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

ulli solve(vector<ulli> &arr)
{
    // find gcd of all elements
    ulli gcd = arr[0];
    for (ulli i = 1; i < arr.size(); i++)
        gcd = __gcd(gcd, arr[i]);

    return gcd * arr.size();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    ulli tc;
    cin >> tc;

    while (tc--)
    {
        ulli size;
        cin >> size;
        vector<ulli> arr(size);
        for (ulli i = 0; i < size; i++)
            cin >> arr[i];

        cout << solve(arr) << endl;
    }

    return 0;
}
