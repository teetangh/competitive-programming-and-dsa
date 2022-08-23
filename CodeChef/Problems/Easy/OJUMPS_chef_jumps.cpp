#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

typedef long long int lli;

string chef_jumping(lli input)
{
    if (input == 0 || input == 1 || input == 3 || input == 6)
        return "yes";
    else if (input == 2 || input == 4 || input == 5)
        return "no";

    else
        return chef_jumping(input % 6);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    lli input;
    cin >> input;
    cout << chef_jumping(input);
}
