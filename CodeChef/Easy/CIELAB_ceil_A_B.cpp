#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;
    int diff = abs(a - b);

    if (diff % 10 == 0 || diff == 1)
        cout << diff + 1 << endl;
    else
        cout << diff - 1 << endl;
}
