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

lli calculate_coins(lli input)
{
    lli output = input / 2 + input / 3 + input / 4;

    if (output < input)
        return input;

    return output;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    lli input;
    int counter = 0;
    while (cin >> input)
    {
        counter++;
        cout << calculate_coins(input) << endl;
        if (counter >= 10)
            break;
    }

    return 0;
}
