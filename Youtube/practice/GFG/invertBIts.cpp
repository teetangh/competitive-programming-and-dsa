#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long int lli;

using namespace std;

void invertBits(lli num)
{
    int x = log2(num) + 1;

    for (int i = 0; i < x; i++)
        num = (num ^ (1 << i));

    cout << num;
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
        lli num;
        cin >> num;
        invertBits(num);
    }
}
