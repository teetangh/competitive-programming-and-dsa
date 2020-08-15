#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Global Variables -> bad practice
// Use Reference Variables instead
int a;

void g()
{
    a++;
    cout << a << endl;
}
void f()
{
    cout << a << endl;
    a++;
    g();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    a = 10;
    f();
    cout << a << endl;
}
