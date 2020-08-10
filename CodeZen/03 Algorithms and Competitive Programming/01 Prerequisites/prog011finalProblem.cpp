// Lead Game
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    // cs = cumulative score
    int cs1 = 0, cs2 = 0;
    int max_lead = 0;
    int max_lead_player = 1;

    while (n--)
    {
        int s1, s2;
        cin >> s1 >> s2;
        cs1 += s1;
        cs2 += s2;

        int curr_lead = 0;
        int curr_lead_player = 1;
        if (cs1 >= cs2)
            curr_lead = cs1 - cs2;
        else
        {
            curr_lead_player = 2;
            curr_lead = cs2 - cs1;
        }

        if (curr_lead > max_lead)
        {
            max_lead = curr_lead;
            max_lead_player = curr_lead_player;
        }
    }

    cout << max_lead_player << " " << max_lead;

    return 0;
}

// // Sample IO
// 5

// 140 82
// 89 134
// 90 110
// 112 106
// 88 90

// 1 58