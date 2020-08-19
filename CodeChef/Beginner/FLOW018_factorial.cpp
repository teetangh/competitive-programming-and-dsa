#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    else
        return n * factorial(n - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    int n;
    while (test_cases--)
    {
        cin >> n;
        cout << factorial(n) << endl;
    }
}

// Input
// 3 
// 3 
// 4
// 5

// Output

// 6
// 24
// 120