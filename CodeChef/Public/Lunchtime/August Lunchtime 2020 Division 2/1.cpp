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
        int size;
        cin >> size;

        map<int, int> mp;
        mp.clear();
        int n;
        for (int i = 0; i < size; i++)
        {
            cin >> n;
            mp[n]++;
        }

        pair<int, int> entryWithMaxValue = make_pair(0, 0);
        map<int, int>::iterator currentEntry;

        map<int, int> mp2;
        for (auto &ele : mp)
            mp2[ele.second]++;

        for (currentEntry = mp2.begin(); currentEntry != mp2.end(); ++currentEntry)
        {
            if (currentEntry->second > entryWithMaxValue.second)
                entryWithMaxValue = make_pair(currentEntry->first, currentEntry->second);
        }
        cout << entryWithMaxValue.first << endl;

        mp.clear(), mp2.clear();
    }
    return 0;
}
