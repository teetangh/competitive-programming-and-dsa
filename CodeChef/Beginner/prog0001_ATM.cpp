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
