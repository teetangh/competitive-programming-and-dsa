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

    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    for (int col = 0; col < n; col++)
    {
        if ((col % 2) == 0)
            for (int row = 0; row < n; row++)
                cout << arr[row][col] << " ";
        else
            for (int row = n - 1; row >= 0; row--)
                cout << arr[row][col] << " ";
    }

    for (int i = 0; i < n; i++)
        delete arr[i];
    delete[] arr;
}

// // Sample IO
// 4

// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44


// Output
// 11 21 31 41 42 32 22 12 13 23 33 43 44 34 24 14 