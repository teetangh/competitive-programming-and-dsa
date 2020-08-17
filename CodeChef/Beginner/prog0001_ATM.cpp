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

    int withdraw;
    float balance;

    cin >> withdraw >> balance;
    double output = balance;
    if (withdraw % 5 == 0 && balance - withdraw - 0.5 >= 0)
        output = balance - withdraw - 0.5;

    printf("%.2f", output);
    return 0;
}

// Example - Successful Transaction
// Input:
// 30 120.00

// Output:
// 89.50
// Example - Incorrect Withdrawal Amount (not multiple of 5)
// Input:
// 42 120.00

// Output:
// 120.00
// Example - Insufficient Funds
// Input:
// 300 120.00

// Output:
// 120.00