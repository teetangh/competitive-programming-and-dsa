// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int solve(int num)
{

    int result = 0;
    const int MOD = 1e9 + 7;
    for (int i = 0; i <= num; i++)
    {
               
        

    }

    return (result % MOD);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin); // for getting input from xinput.txt
#endif
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;
    int A;
    while (tc--)
    {
        cin >> A;
        cout << solve(A) << endl;
    }
}
