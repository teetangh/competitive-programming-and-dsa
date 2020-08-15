#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void g(int const &a)
{
    // a++; // Passed by const reference
}

void f(const int *p)
{
    // (*p)++; //Passed by Const Reference
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int const i = 10;
    int const *p = &i;
    // (*p)++;

    int j = 12;
    int *p3 = &j;
    f(p3);
    g(j);

    int const *p2 = &j;
    cout << *p2 << endl;
    j++;
    cout << *p2 << endl;
}
