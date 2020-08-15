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

    int a[] = {1, 2, 3};
    char b[] = "abc";
    cout << a << endl;
    cout << b << endl;

    char *c = &b[0];
    cout << c << endl;

    char c1 = 'a';
    char *pc = &c1;

    cout << c1 << endl;
    cout << pc << endl; // prints till null character

    char str[] = "abcde";
    // char *pstr = "abcde"; // not recommended // points to temporary memory
}
