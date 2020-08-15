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

    // Have to initialise here itself
    const int i = 10;

    // Constant Reference from a non const int
    int j = 12;
    const int &k = j;

    j++;
    // k++;  // Cannot increase via const reference
    cout << " i " << i << " j " << i << " k " << i << endl;

    // Const Reference from a const int
    int const j2 = 12;
    int const &k2 = j2;

    // j2++; // Both are constant
    // k2++; // Both are constant

    // Refernce from a const int
    int const j3 = 123;
    // int &k3 = j3;  // If i read access i cannot grant others write access
    // k3++;
}
