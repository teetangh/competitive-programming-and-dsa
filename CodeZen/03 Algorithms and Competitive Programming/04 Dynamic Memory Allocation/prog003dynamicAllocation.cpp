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

    int *p = new int;
    *p = 10;
    cout << *p << endl;

    double *pd = new double;
    char *c = new char;

    int *pa = new int[50];

    int n;
    cin >> n;

    int *pa2 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> pa2[i];

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < pa2[i])
            max = pa2[i];
    }

    cout << max << endl;
    pa2[0] = 10;

    delete p;
    delete pd;
    delete c;
    delete[] pa;
    delete[] pa2;
}
