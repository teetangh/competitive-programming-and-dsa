#include <iostream>
#include <iomanip>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef pair<int, int> pii;

bool isLessThan(pair<int, int> arrival_departure_times1, pair<int, int> arrival_departure_times2)
{
    return arrival_departure_times1.first < arrival_departure_times2.first;
}

// bool isTimeEqual(pair<int, int> arrival_departure_times, int i)
// {
//     return arrival_departure_times.first == i;
// }
void showpq(priority_queue<int, vector<int>, greater<int>> gq)
{
    priority_queue<int, vector<int>, greater<int>> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

void printMAP(map<int, priority_queue<int, vector<int>, greater<int>>> times_table)
{
    cout << "==========================================\n";
    for (auto &ele : times_table)
    {
        cout << ele.first << ":";
        showpq(ele.second);
    }
    cout << "==========================================\n";
}

int min_num_of_chairs(vector<pair<int, int>> arrival_departure_times, int min_in_time, int max_out_time)
{

    sort(arrival_departure_times.begin(), arrival_departure_times.end(), isLessThan);

    // for (auto &ele : arrival_departure_times)
    //     cout << ele.first << " " << ele.second << " \n";
    // cout << "\n";

    // map<int, int> mp;
    // for (int i = min_in_time; i <= max_out_time; i++)
    // {
    //     // if (arrival_departure_times.first == i)
    //     std::find_if(arrival_departure_times.begin(), arrival_departure_times.end(), isTimeEqual(arrival_departure_times, i));
    // }

    int seat_count = 0;
    int max_seat_count = INT_MIN;
    int i_again;
    map<int, priority_queue<int, vector<int>, greater<int>>> times_table;
    for (int i = min_in_time; i <= max_out_time; i++)
    {
        i_again = i;
        // Get the first element
        if (!arrival_departure_times.empty())
        {
            auto front = arrival_departure_times[0];

            if (i == front.first)
            {
                i_again = i - 1;
                times_table[i].push(front.second);
                seat_count++;
                if (max_seat_count < seat_count)
                    max_seat_count = seat_count;

                // Delete the first element
                if (arrival_departure_times.size())                                 //check if there any elements in the vector array
                    arrival_departure_times.erase(arrival_departure_times.begin()); //erase the first element
            }
        }
        for (auto &ele : times_table)
        {
            if (i == ele.second.top())
            {
                ele.second.pop();
                seat_count--;
                if (ele.second.empty())
                    times_table.erase(ele.first);
            }
        }
        // cout << "i " << i << " seat_count " << seat_count << endl;
        // printMAP(times_table);
        i = i_again;
    }

    return max_seat_count;
}

// int min_num_of_chairs(priority_queue<pii, vector<pii>, greater<pii>> arrival_departure_times, int min_in_time, int max_out_time)
// {
//     for (int i = min_in_time; i <= max_out_time; i++)
//     {
//         /* code */
//     }
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int num_of_people;
    cin >> num_of_people;

    // vector<int> arrival_times(num_of_people);
    // vector<int> departure_times(num_of_people);
    vector<pair<int, int>> arrival_departure_times(num_of_people);

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
    }

    // priority_queue<pii, vector<pii>, greater<pii>> arrival_departure_times;

    // for (int i = 0; i < num_of_people; i++)
    //     arrival_departure_times.push(std::make_pair(arrival_times[i], departure_times[i]));

    cout << min_num_of_chairs(arrival_departure_times, min_in_time, max_out_time);
}
