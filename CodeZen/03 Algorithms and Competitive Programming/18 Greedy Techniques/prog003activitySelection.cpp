// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;

bool custom(const pair<lli, lli> &p1, const pair<lli, lli> &p2)
{
    if (p1.second < p2.second)
        return true;
    else if (p1.second == p2.second)
        return p1.first > p2.first;
    else
        return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    vector<pair<lli, lli>> vpii(tc);

    for (int i = 0; i < tc; i++)
        cin >> vpii[i].first >> vpii[i].second;

    sort(vpii.begin(), vpii.end(), custom);

    lli current_ending = vpii[0].second;
    int acitivity_count = 0;

    for (int i = 1; i < vpii.size(); i++)
    {
        if (current_ending <= vpii[i].first)
        {
            acitivity_count++;
            current_ending = vpii[i].second;
        }
    }
    acitivity_count++;

    cout << acitivity_count << endl;
}