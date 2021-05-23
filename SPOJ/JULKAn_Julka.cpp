// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

// Defines
#define ull unsigned long long
#define ulli unsigned long long int

using namespace std;

void print_apple_distribution(ull apples, ull difference)
{
    ull Klaudia, Natalia;
    Klaudia = Natalia = apples / 2;

    difference /= 2;
    while (difference--)
    {
        Klaudia += 1;
        Natalia -= 1;
    }
    cout << Klaudia << endl;
    cout << Natalia << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases = 1;
    ulli apples, difference;

    while (test_cases--)
    {
        cin >> apples >> difference;
        print_apple_distribution(apples, difference);
    }
    return 0;
}
