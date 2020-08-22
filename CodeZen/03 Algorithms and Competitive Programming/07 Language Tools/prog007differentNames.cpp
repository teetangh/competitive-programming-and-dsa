#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    string s, T;

    getline(cin, s);

    stringstream X(s);

    map<string, int> strings_map;

    while (getline(X, T, ' '))
        strings_map[T]++;

    bool none_repeating = true;
    for (auto &ele : strings_map)
    {
        if (ele.second <= 1)
            continue;
        else
        {
            none_repeating = false;
            cout << ele.first << " " << ele.second << endl;
        }
    }

    if (none_repeating == true)
        cout << -1 << endl;

    return 0;
}
