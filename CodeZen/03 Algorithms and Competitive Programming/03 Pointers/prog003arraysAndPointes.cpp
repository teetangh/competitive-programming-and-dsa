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

    int a[10];
    cout << a << endl;
    cout << &a[0] << endl;

    a[0] = 5;
    a[1] = 10;
    cout << *a << endl;
    cout << *(a + 1) << endl;

    int *p = &a[0];
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;

    cout << sizeof(p) << endl;
    cout << sizeof(a) << endl;

    p = p + 1;
    // a = a + 1; // ERROR
}
