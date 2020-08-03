#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int calculate_last_digit(int a, int b)
{

    vector<vector<int>> roundTable = {
        {0},
        {1},
        {2, 4, 8, 6},
        {3, 9, 7, 1},
        {4, 6},
        {5},
        {6},
        {7, 9, 3, 1},
        {8, 4, 2, 6},
        {9, 1}};

    cout << "Here" << endl;

    if (a != 0 && b == 0)
        return 1;
    else if (a == 0 && b == 0)
        return 0;
    else
    {
        int b2 = b % (roundTable[a].size() - 1);

        // n = 0.5 * (n + lower + fabs(n - lower));
        // n = 0.5 * (n + upper - fabs(upper - n));

        int lower = 0;
        b2 = int(0.5 * (b2 + lower + abs(b2 - lower)));

        return roundTable[a][(b2)];
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    queue<int> mq;

    int a, b;
    while (test_cases--)
    {
        cin >> a >> b;
        mq.push(calculate_last_digit(a, b));
    }

    while (!mq.empty())
    {
        int temp = mq.front();
        mq.pop();
        cout << temp << endl;
    }

    return 0;
}
