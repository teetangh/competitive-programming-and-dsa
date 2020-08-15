#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    // cout << n << endl;

    if (n == 0 || n == 1)
        return 1;

    int smallOutput = factorial(n - 1);
    return n * smallOutput;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    int output = factorial(n);
    cout << output;
}
