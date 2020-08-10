#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

bool canDistributeEqually(int fruits)
{
    if ((fruits % 11) == 1)
        return true;
    else
        return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int fruits;
    cin >> fruits;

    int fullMoons = 0;

    while (!canDistributeEqually(fruits))
    {
        fullMoons += 1;
        fruits = 2 * fruits;
    }

    cout << fullMoons << " " << fruits << endl;
}
// // Sampe IO
// 14

// 2 56
