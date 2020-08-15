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

    int m, n;
    cin >> m >> n;
    int **p = new int *[m];
    for (int i = 0; i < n; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < m; i++)
        delete[] p[i];

    delete[] p;
}
