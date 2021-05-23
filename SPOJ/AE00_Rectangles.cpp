#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int num_of_rectangles(int squares)
{
    // just count the no of divisors upto((floor)sqrt(i)) where 1<=i<=n
    int rectangles = 0;
    for (int i = 1; i <= squares; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
                rectangles++;
        }
    }
    return rectangles;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int squares;
    cin >> squares;
    cout << num_of_rectangles(squares);
    return 0;
}
