#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef long long int lli;

void dec2Bin(int n)
{
    int binaryNum[32];

    int i;
    for (i = 0; n > 0; i++)
    {
        binaryNum[i] = n % 2;
        n /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << binaryNum[j];
    }

    cout << endl;
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

    int n;
    while (test_cases--)
    {
        cin >> n;
        dec2Bin(n);
    }
}
