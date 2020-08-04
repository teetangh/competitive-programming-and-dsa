#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int basic_exponentiation(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        int y = basic_exponentiation(x, n / 2);
        return y * y;
    }
    else
        return x * basic_exponentiation(x, n - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    queue<int> mq;

    int x, n;
    while (test_cases--)
    {
        cin >> x >> n;
        mq.push(basic_exponentiation(x, n));
    }
    while (!mq.empty())
    {
        int temp = mq.front();
        mq.pop();
        cout << temp << endl;
    }
}