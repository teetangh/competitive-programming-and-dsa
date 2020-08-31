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
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++)
        {
            int start, end;
            cin >> start >> end;
            intervals.push_back(make_pair(start, end));
        }

        sort(intervals.begin(), intervals.end());

        while (m--)
        {
            int curr_time;
            cin >> curr_time;
            int position = lower_bound(intervals.begin(), intervals.end(), make_pair(curr_time, 0)) - intervals.begin();

            // When curr time matches with zeroth position
            if (position == 0)
            {
                int ans = intervals[0].first - curr_time;
                cout << ans << endl;
            }
            else
            {
                int ans = -1;
                // Comparing with just before this position
                if (intervals[position - 1].second > curr_time)
                    ans = 0;
                else if (position < intervals.size())
                {
                    // position lies in intervals
                    ans = intervals[position].first - curr_time;
                }
                // if ans remained -1 that means position lies out of bounds
                cout << ans << endl;
            }
        }
    }
}
