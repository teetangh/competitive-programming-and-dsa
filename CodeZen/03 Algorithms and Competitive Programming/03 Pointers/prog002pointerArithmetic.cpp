#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int i = 10;
    int *p = &i;

    cout << p << endl;
    p = p + 2;
    cout << p << endl;

    cout << p << endl;
    p = p - 2;
    cout << p << endl;

    double d = 102.3;
    double *pd = &d;
    cout << pd << endl;
    pd = pd + 1;
    cout << pd << endl;
}
