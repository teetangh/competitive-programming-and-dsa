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

    while (test_cases--)
    {
        vector<pair<int, int>> time_slots;
        int Nintervals, Mpeople;
        cin >> Nintervals >> Mpeople;

        while (Nintervals--)
        {
            int a, b;
            cin >> a >> b;
            time_slots.push_back(make_pair(a, b));
        }

        sort(time_slots.begin(), time_slots.end());

        while (Mpeople--)
        {
            int person;
            cin >> person;
            auto it = lower_bound(time_slots.begin(), time_slots.end(), make_pair(person, 0));
            auto prev_it = it - 1;
            if (prev_it->first <= person && person < prev_it->second)
                cout << 0 << endl;
            else if (it == time_slots.end() && person > it->second)
                cout << -1 << endl;
            else if (person >= prev_it->second)
                cout << it->first - person << endl;
        }
    }
    return 0;
}
// Example Input
// 1
// 4 5
// 5 7
// 9 10
// 2 3
// 20 30
// 5
// 6
// 7
// 35
// 1
// Example Output
// 0
// 0
// 2
// -1
// 1