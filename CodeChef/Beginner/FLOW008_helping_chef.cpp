#include <iostream>
#include <iomanip>
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
    // cout << test_cases;

    int n;
    while (test_cases--)
    {
        cin >> n;
        if (n < 10)
            cout << "Thanks for helping Chef!" << endl;
        else
            cout << -1 << endl;
    }
}
// Input
// 3 
// 1
// 12
// -5
// Output
// Thanks for helping Chef!
// -1
// Thanks for helping Chef!