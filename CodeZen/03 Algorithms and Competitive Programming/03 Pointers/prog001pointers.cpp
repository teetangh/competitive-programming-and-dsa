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

    // Declaring the varaibles
    int i = 10;
    cout << &i << endl;

    // Making the pointer
    int *p = &i;
    cout << p << endl;
    cout << *p << endl;
    cout << sizeof(p) << endl;
    int *q = p;

    // Incrementing the pointers
    cout << i << endl;
    cout << *p << endl;
    i++;
    cout << i << endl;
    cout << *p << endl;

    // Incrementing an independant varible
    int a = *p;
    a++;
    cout << a << endl;
    cout << *p << endl;

    i = 121;
    cout << i << endl;
    cout << *p << endl;
    cout << *q << endl;

    *p = 23;
    cout << i << endl;
    cout << *p << endl;
    cout << *q << endl;

    (*p)++;
    cout << i << endl;
    cout << *q << endl;
    cout << *p << endl;

    // Float Pointers
    float f = 10.2;
    float *pf = &f;
    cout << pf << endl;

    // Double Pointers
    double d = 122.32;
    double *pd = &d;
    cout << pd << endl;

    // Dangling pointers
    int j;
    cout << j << endl;

    j++;
    cout << j << endl;

    // Very Dangerous. Don't do this.
    int *p;  // int *p = 0; (Safer and will give Compilation error)
    cout << p << endl;
    (*p)++;
    cout << p << endl;
}
// // Sample IO
// 0x7fffaf3cd14c
// 0x7fffaf3cd14c
// 10
// 8
// 10
// 10
// 11
// 11
// 12
// 11
// 121
// 121
// 23
// 23
// 24
// 24
// 0x7fffaf3cd150
// 0x7fffaf3cd158

