// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

lli num_of_substrings(lli input, int digits)
{
    int count = 0;
    while (input)
    {
        count += input % 10;
        input /= 10;
    }
    // cout << count << endl;
    return count * (digits - count);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    while (test_cases--)
    {
        int digits;
        lli input;

        cin >> digits >> input;
        cout << num_of_substrings(input, digits) << endl;
    }
    return 0;
}
