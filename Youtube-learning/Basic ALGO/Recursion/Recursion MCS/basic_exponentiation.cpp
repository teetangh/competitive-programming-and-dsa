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
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    int x, n;

    while (test_cases--)
    {
        cin >> x >> n;
        cout << basic_exponentiation(x, n) << endl;
    }
    return 0;
}
// // Sample IO
// 2
// 2 2 
// 7 3 

// 4
// 343
