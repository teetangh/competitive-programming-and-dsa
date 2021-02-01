// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int min_salary(int *captains, int *assistants, int pilots, int assistant_captain_difference, vector<vector<int>> &dp)
{
    if (pilots == 0)
        return 0;

    if (dp[pilots][assistant_captain_difference] != -1)
        return dp[pilots][assistant_captain_difference];

    if (assistant_captain_difference == 0)
        return dp[pilots][assistant_captain_difference] = assistants[0] + min_salary(captains + 1, assistants + 1, pilots - 1, 1, dp);

    else if (assistant_captain_difference == pilots)
        return dp[pilots][assistant_captain_difference] = captains[0] + min_salary(captains + 1, assistants + 1, pilots - 1, assistant_captain_difference - 1, dp);

    else
        return dp[pilots][assistant_captain_difference] = min(
                   assistants[0] + min_salary(captains + 1, assistants + 1, pilots - 1, assistant_captain_difference + 1, dp),
                   captains[0] + min_salary(captains + 1, assistants + 1, pilots - 1, assistant_captain_difference - 1, dp));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int N;
    cin >> N;

    int *captains = new int[N + 1];
    int *assistants = new int[N + 1];

    for (int i = 0; i < N; i++)
        cin >> captains[i] >> assistants[i];

    vector<vector<int>> dp;
    dp.resize(N + 1, vector<int>(N / 2 + 1, -1));

    cout << min_salary(captains, assistants, N, 0, dp) << endl;

    return 0;
}

// Sample
// input
// 4
// 5000 3000
// 6000 2000
// 8000 1000
// 9000 6000

// output
// 19000

// input
// 6
// 10000 7000
// 9000 3000
// 6000 4000
// 5000 1000
// 9000 3000
// 8000 6000

// output
// 32000
