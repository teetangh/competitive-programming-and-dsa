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

    int test_cases;
    cin >> test_cases;

    int a, b;
    while (test_cases--)
    {
        cin >> a >> b;
        cout << a % b << endl;
    }

    return 0;
}

// Input
// 3
// 1 2
// 100 200
// 40 15

// Output
// 1
// 100
// 10