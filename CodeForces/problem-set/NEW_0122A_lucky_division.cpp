// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

bool checkLucky(int number)
{
    int temp = number;
    while (temp != 0)
    {
        int x = temp / 10;
        int y = temp % 10;
        if (y != 7 && y != 4)
            return false;
        temp = x;
    }

    return true;
}

bool luckyDivision(int number)
{
    bool justLucky = checkLucky(number);
    if (justLucky)
        return true;

    for (int i = 1; i <= 10; i++)
    {
        int currentPower = pow(2, i);
        if (number % currentPower == 0 && checkLucky(currentPower))
            return true;
    }

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int number;
    cin >> number;

    if (luckyDivision(number))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
