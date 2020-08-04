#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int modular_exponentiation(int x, int n, int M)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        int y = modular_exponentiation(x, n / 2, M);
        return (y * y) % M;
    }
    else
        return ((x % M) * modular_exponentiation(x, n - 1, M)) % M;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    int x, n;
    int M = 10;
    queue<int> mq;
    while (test_cases--)
    {
        cin >> x >> n;
        mq.push(modular_exponentiation(x, n, M));
    }
    while (!mq.empty())
    {
        int temp = mq.front();
        mq.pop();
        cout << temp << endl;
    }
    return 0;
}
