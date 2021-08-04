// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define N 101

int arr[N][N], I[N][N];

void printMatrix(int A[][N], int dim)
{
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void multiplyMatrix(int A[][N], int B[][N], int dim)
{
    int res[dim + 1][dim + 1];

    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for (int k = 1; k <= dim; k++)
                res[i][j] = res[i][j] + A[i][k] * B[k][j]; // can use modular exponentiation here
        }
    }
    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
            A[i][j] = res[i][j];
}

void power(int A[][N], int dim, int n)
{
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    // Naive Multiplication
    // for (int i = 1; i <= n; i++)
    //     multiplyMatrix(I, A, dim); // I = I * A;

    // Binary Exponentiation on Matrix
    while (n)
    {
        if (n % 2) // Odd power
            multiplyMatrix(I, A, dim), n--;
        else // Even Power
            multiplyMatrix(A, I, dim), n /= 2;
    }

    for (int i = 1; i <= dim; i++)
        for (int j = 1; j <= dim; j++)
            A[i][j] = I[i][j];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, dim, n;
    cin >> tc;

    while (tc--)
    {
        cin >> dim >> n;
        for (int i = 1; i <= dim; i++)
            for (int j = 1; j <= dim; j++)
                cin >> arr[i][j];

        power(arr, dim, n);
        printMatrix(arr, dim);
    }
}

// // Sample IO
// 3

// 2 1
// 1 2
// 2 3

// 2 2
// 0 1
// 1 1

// 3 3
// 1 0 4
// 1 2 2
// 0 4 4

// // OUTPUT
// 1 2
// 2 3

// 1 1
// 1 2

// 17 112 116
// 15 88 100
// 28 144 160
