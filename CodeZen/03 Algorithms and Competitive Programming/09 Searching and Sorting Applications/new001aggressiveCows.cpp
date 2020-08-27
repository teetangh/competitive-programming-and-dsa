#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli min_distance(vector<lli> stalls_vec, lli cows)
{
    sort(stalls_vec.begin(), stalls_vec.end());

    lli low = stalls_vec[0];
    lli high = stalls_vec[stalls_vec.size() - 1] - stalls_vec[0];

    vector<pair<lli, bool>> cows_stalls_vec(stalls_vec.size());
    for (lli i = 0; i < cows_stalls_vec.size(); i++)
        cows_stalls_vec[i].first = stalls_vec[i];

    // cout << "\n\n";
    // for (auto &ele : cows_stalls_vec)
    //     cout << ele.first << " " << ele.second << "|";
    // cout << "\n\n";

    while (low <= high)
    {
        lli mid = (low + high) / 2;
        lli d = mid;

        for (auto &ele : cows_stalls_vec)
            ele.second = false;

        cows_stalls_vec[0].second = true;
        cows_stalls_vec[cows_stalls_vec.size() - 1].second = true;
        lli cows_counter = cows - 2;

        for (lli i = 1; i < cows_stalls_vec.size() - 1; i++)
        {
            


            if (cows_counter <= 0)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // for (lli i = 1; i < cows_stalls_vec.size() - 1; i++)
        // {
        //     // if(cows_stalls_vec[i - d])

        //     if ((abs(cows_stalls_vec[i - 1].first - cows_stalls_vec[i].first) >= d) && (abs(cows_stalls_vec[i + 1].first - cows_stalls_vec[i].first) >= d))

        //     {
        //         cows_stalls_vec[i].second == true;
        //         cows_counter--;
        //     }

        //     // lli last_cow_index = i;
        //     // for (lli j = last_cow_index + 1; j < cows_stalls_vec.size(); j++)
        //     // {
        //     //     if (abs(cows_stalls_vec[j].first - cows_stalls_vec[i].first) >= d &&
        //     //         abs(cows_stalls_vec[]))
        //     // }
        // }

        if (cows_counter <= 0)
            return d;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    lli Nstalls, cows;

    while (test_cases--)
    {
        cin >> Nstalls >> cows;
        vector<lli> stalls_vec(Nstalls);
        for (lli i = 0; i < Nstalls; i++)
            cin >> stalls_vec[i];

        cout << min_distance(stalls_vec, cows) << endl;
    }
    return 0;
}
