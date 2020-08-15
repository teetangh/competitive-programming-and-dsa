#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void increment1(int **p)
{
    p = p + 1;
}

void increment2(int **p)
{
    *p = *p + 1;
}
void increment2(int **p)
{
    **p = **p + 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int i = 10;
    int *p = &i;

    int **p2 = &p;

    // Address Variables
    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;

    // Actual Values
    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;
}
