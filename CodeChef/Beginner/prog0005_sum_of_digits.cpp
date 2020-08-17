#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

typedef long long ll;
typedef long long int lli;

using namespace std;

int sum_of_digits(lli number)
{
    int sum = 0;
    while (number > 0)
    {
        int y = number % 10;
        sum += y;
        number = number / 10;
    }
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    lli n;
    while (test_cases--)
    {
        cin >> n;
        cout << sum_of_digits(n) << endl;
    }

    return 0;
}
// // Sample IO
// 3 
// 12345
// 31203
// 2123

// 15
// 9
// 8
