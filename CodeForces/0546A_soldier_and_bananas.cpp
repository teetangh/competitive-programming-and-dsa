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

int getBorrow(int k, int n, int w)
{
    int totalCost = 0;
    for (int i = 1; i <= w; i++)
        totalCost += i * k;

    int borrow = totalCost - n;
    if (borrow < 0)
        return 0;
    else
        return borrow;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int k, n, w;
    cin >> k >> n >> w;

    cout << getBorrow(k, n, w) << endl;
}
