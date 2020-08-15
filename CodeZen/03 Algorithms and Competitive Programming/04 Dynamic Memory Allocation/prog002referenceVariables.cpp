#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void increment(int &n)
{
    n++;
}

/////// BAD PRACTICE/////////
// int &f(int n)
// {
//     int a = n;
//     return a;
// }

// int *f2()
// {
//     int i = 10;
//     return &i;
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int i = 10;
    int &j = i; // can't do this in 2 lines

    i++;
    cout << "i= " << i << " j= " << j << endl;

    // Changing the values
    int k = 100;
    j = k;
    cout << "i= " << i << " j= " << j << endl;

    // Incrementing by reference
    increment(i);
    cout << "i= " << i << " j= " << j << endl;

    // int &k = f(i);
    // int &k2 = f();
    cout << k << endl;
}
