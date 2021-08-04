// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// O(n)
int power(int base, int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * base;

    return res;
}

// O(log n)
int powerBE(int a, int n)
{
    int res = 1;

    while (n)
    {
        if (n % 2) // odd power
            res *= 2, n--;
        else // even power
            a *= a, n /= 2;
    }
    return res;
}

// O(log n)
int powerME(int a, int n, int p)
{
    int res = 1;

    while (n)
    {
        if (n % 2) // odd power
            res = (res * 2) % p, n--;
        else // even power
            a = (a * a) % p, n /= 2;
    }
    return res;
}
