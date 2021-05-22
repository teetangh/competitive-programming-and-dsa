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

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    int x, n, M;
    while (test_cases--)
    {
        cin >> x >> n >> M;
        cout << modular_exponentiation(x, n, M) << endl;
    }
}
// // Sample IO
// 2
// 2 2 10
// 7 3 10

// 4
// 3
