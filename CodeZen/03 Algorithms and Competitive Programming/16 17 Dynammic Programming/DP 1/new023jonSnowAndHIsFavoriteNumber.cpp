// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> rangers_count(1025, 0);
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        rangers_count[temp]++;
    }

    // for (auto &ele : rangers_count)
    //     cout << ele << " ";

    // Instead of sorting repeatedly we maintain a hashmap which is already ordered

    for (int i = 0; i < k; i++)
    {
        bool turn = true;

        vector<int> exor_rangers_count(1025, 0);

        for (int j = 0; j < 1025; j++)
        {
            if (rangers_count[j] == 0)
                continue;

            auto original = rangers_count[j];
            auto exor = j ^ x;

            // cout << "\n exor \n"
            //      << exor << endl;

            if (turn == true)
            {
                if (original % 2 == 0)
                {
                    exor_rangers_count[exor] += (rangers_count[j] / 2);
                }
                else
                {
                    exor_rangers_count[exor] += (rangers_count[j] / 2 + 1);
                    turn ^= 1;
                }
                exor_rangers_count[j] = rangers_count[j] / 2;
            }
            else
            {
                if (original % 2 == 0)
                {
                    exor_rangers_count[j] = rangers_count[j] / 2;
                }
                else
                {
                    exor_rangers_count[j] = rangers_count[j] / 2 + 1;
                    turn ^= 1;
                }
                exor_rangers_count[exor] += (rangers_count[j] / 2);
            }
        }

        std::copy(exor_rangers_count.begin(), exor_rangers_count.end(), rangers_count.begin());
    }

    // for (auto &ele : rangers_count)
    //     cout << ele << " ";

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < 1025; i++)
    {
        if (rangers_count[i] > 0 && i >= max)
            max = i;
    }

    for (int i = 0; i < 1025; i++)
    {
        if (rangers_count[i] > 0 && i <= min)
            min = i;
    }

    cout << max << " " << min << endl;

    // cout << *max_element(rangers_count.begin(), rangers_count.end()) << " ";
    // cout << *min_element(rangers_count.begin(), rangers_count.end());
}
