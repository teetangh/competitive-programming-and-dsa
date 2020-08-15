#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    int smallOutput1 = fib(n - 1);
    int smallOutput2 = fib(n - 2);

    return smallOutput1 + smallOutput2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    int n;
    while (test_cases--)
    {
        cin >> n;
        cout << fib(n) << endl;
    }
}
// // Sample IO
// 5
// 6 7 8 9 10

// 8
// 13
// 21
// 34
// 55
