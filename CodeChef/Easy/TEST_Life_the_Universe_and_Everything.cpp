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

    int n;
    while (1)
    {
        cin >> n;
        if (n != 42)
            cout << n << endl;
        else
            break;
    }

    return 0;
}
