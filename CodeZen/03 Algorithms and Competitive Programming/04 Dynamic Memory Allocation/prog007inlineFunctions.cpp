#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;

    // int c;
    // if (a > b)
    //     c = a;
    // else
    //     c = b;
    // cout << c;

    // int c = (a > b) ? a : b;
    int c = max(a, b);
    cout << c << endl;

    int x = 12;
    int y = 34;
    int z = max(x, y);
    cout << z << endl;
}
