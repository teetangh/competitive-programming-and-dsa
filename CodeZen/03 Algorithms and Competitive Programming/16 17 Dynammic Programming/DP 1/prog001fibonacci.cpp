#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;
// typedefs
typedef long long ll;
typedef long long int lli;

// Time: O(2^n)
int fib(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

// Recursive
// Time: O(2n)
int fib2(int n, int *arr)
{
    if (n == 0 || n == 1)
        return 1;

    if (arr[n] > 0)
        return arr[n];

    int output = fib2(n - 1, arr) + fib2(n - 2, arr);
    arr[n] = output;
    return output;
}

// Iterative
// Time: O(n)
int fib3(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    int output = arr[n];
    delete[] arr;
    return output;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << fib(n) << endl;

    int *arr = new int[n + 1];
    cout << fib2(n, arr) << endl;

    cout << fib3(n) << endl;
}
// // Sample IO
// 20
// 10946
// 10946
// 10946
