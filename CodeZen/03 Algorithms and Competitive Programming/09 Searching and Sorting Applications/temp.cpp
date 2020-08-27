#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

typedef long long int lli;

bool check_distance(vector<lli> positions, vector<lli> cows_positions, int index, int d)
{
    for (int i = index - d; i <= index + d; i++)
    {
        auto it = find(cows_positions.begin(), cows_positions.end(), positions[i]);
        if (it != cows_positions.end())
            continue;
        else
            return false;
    }
    return true;
}

lli min_distance(vector<lli> positions, lli cows)
{
    sort(positions.begin(), positions.end());

    int min_dist = 0;
    int max_dist = positions[positions.size() - 1] - positions[0];

    lli low = min_dist;
    lli high = max_dist;

    lli mid;
    lli d;
    lli cow_counter;
    while (low <= high)
    {

        vector<lli> cows_positions;
        cows_positions.clear();

        cows_positions.push_back(positions[0]);
        cows_positions.push_back(positions[positions.size() - 1]);

        mid = (low + high) / 2;
        d = mid;
        cow_counter = cows - 2;

        for (int i = 1; i < positions.size() - 1; i++)
        {
            if (check_distance(positions, cows_positions, i, d))
            {
                cows_positions.push_back(positions[i]);
                cow_counter--;
            }
        }
        if (cow_counter == 0)
            low = mid + 1;
        else
            high = mid - 1;

        cout << "cows positions vector" << endl;
        for (auto &ele : cows_positions)
            cout << ele << " ";
        cout << endl;
    }

    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;

    lli Nstalls, cows;

    while (test_cases--)
    {
        cin >> Nstalls >> cows;
        vector<lli> positions(Nstalls);
        for (lli i = 0; i < Nstalls; i++)
            cin >> positions[i];

        cout << min_distance(positions, cows) << endl;
        // cout << min_dist
    }
}
