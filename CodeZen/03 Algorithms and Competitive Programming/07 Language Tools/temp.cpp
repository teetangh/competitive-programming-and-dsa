#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int num_of_people;
    cin >> num_of_people;

    list<pair<int, int>> arrival_departure_times;

    int min_in_time = INT_MAX;
    int max_out_time = INT_MIN;
    for (int i = 0; i < num_of_people; i++)
    {
        cin >> arrival_departure_times[i].first;
        if (min_in_time > arrival_departure_times[i].first)
            min_in_time = arrival_departure_times[i].first;
    }
    for (int i = 0; i < num_of_people; i++)
    {
        cin >> arrival_departure_times[i].second;
        if (max_out_time < arrival_departure_times[i].second)
            max_out_time = arrival_departure_times[i].second;
    },
}
