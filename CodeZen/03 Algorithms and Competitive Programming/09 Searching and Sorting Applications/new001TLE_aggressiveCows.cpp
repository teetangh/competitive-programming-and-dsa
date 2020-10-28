#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// typedefs
typedef long long ll;
typedef long long int lli;

bool check_distance(vector<lli> positions, vector<lli> &cows_positions, lli index, lli mid)
{
    for (lli i = positions[index] - mid + 1; i <= positions[index] + mid - 1; i++)
    {
        if (i < 0 || i > positions[positions.size() - 1])
            continue;

        auto it = find(cows_positions.begin(), cows_positions.end(), i);
        if (it != cows_positions.end())
            return false;
    }
    return true;
}

lli min_distance(vector<lli> positions, lli cows)
{
    lli min_dist = 0;
    sort(positions.begin(), positions.end());

    lli max_dist = positions[positions.size() - 1] - positions[0];

    if (cows == 2)
        return max_dist;

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
        cow_counter = cows - 2;

        for (lli i = 1; i < positions.size() - 1; i++)
        {
            // cout << " i " << i << " d " << d << " low " << low << " high " << high << " mid " << mid << endl;
            if (check_distance(positions, cows_positions, i, mid))
            {
                // cout << " INSERTED " << positions[i] << "WITH D" << d << endl;
                cows_positions.insert(cows_positions.end() - 1, positions[i]);
                cow_counter--;
                if (cow_counter <= 0)
                    break;
            }
        }
        if (cow_counter == 0)
        {
            d = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;

        // // cout << "cows positions vector" << endl;
        // for (auto &ele : cows_positions)
        //     cout << ele << " ";
        // cout << endl;
    }

    return d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    lli test_cases;
    scanf(" %lld", &test_cases);

    lli Nstalls, cows;

    while (test_cases--)
    {
        scanf(" %lld %lld", &Nstalls, &cows);
        vector<lli> positions(Nstalls);
        for (lli i = 0; i < Nstalls; i++)
            scanf(" %lld", &positions[i]);
        printf("%lld\n", min_distance(positions, cows));
    }
    return 0;
}
// Sample Input :
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
// Sample Output:
// 3