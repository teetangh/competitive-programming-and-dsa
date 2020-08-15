#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

#define PI 3.142

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int r;
    cin >> r;
    cout << PI * r * r << endl;
}
