// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    int t = tc;

    unordered_multiset<int> us1, us2;

    for (int j = 1; j <= t; j++)
    {
        int temp;
        cin >> temp;
        us1.insert(temp);
    }
    t--;

    for (int j = 1; j <= t; j++)
    {
        int temp;
        cin >> temp;
        auto it = us1.find(temp);
        if (it != us1.end())
            us1.erase(it);
        us2.insert(temp);
    }
    cout << *(us1.begin()) << endl;

    t--;
    for (int j = 1; j <= t; j++)
    {
        int temp;
        cin >> temp;
        us1.insert(temp);
        auto it = us2.find(temp);
        if (it != us2.end())
            us2.erase(it);
    }
    cout << *(us2.begin()) << endl;
}
