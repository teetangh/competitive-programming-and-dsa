#include <iostream>
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
    if (a != 0 && b == 0)
        return 1;
    else if (a == 0 && b == 0)
        return 0;
    else if (roundTable[a].size() == 1)
    {
        int b2 = b % (roundTable[a].size());
        return roundTable[a][(b2)];
    }
    else
    {
        int b2 = b % (roundTable[a].size());
        return roundTable[a][(b2)-1];
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int test_cases;
    cin >> test_cases;
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
