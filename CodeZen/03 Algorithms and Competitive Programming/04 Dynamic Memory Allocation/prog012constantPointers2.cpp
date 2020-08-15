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
    int j = 21;

    int const *p = &i;
    p = &j; // Can change p pointing
    // (*p)++;

    int *const p2 = &i;
    (*p2)++;
    // p2 = &j;

    const int *const p3 = &i;
    // (*p2)++;
    // p2 = &j;
}
