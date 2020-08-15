#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void incrementPointer(int *p)
{
    p = p + 1;
}

void increment(int *p)
{
    (*p)++;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int i = 10;
    int *p = &i;

    print(p);

    cout << p << endl;
    incrementPointer(p);
    cout << p << endl;

    cout << *p << endl;
    increment(p);
    cout << *p << endl;
}
