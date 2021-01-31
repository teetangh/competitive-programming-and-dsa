// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

pair<int, int> party_problem(const vector<int> &fun, const vector<int> &costs, int parties, int budget)
{
    vector<vector<int>> dp;
    dp.resize(parties + 1, vector<int>(budget + 1, 0));

    for (int i = 1; i < parties + 1; i++)
    {
        for (int j = 1; j < budget + 1; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (costs[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], fun[i - 1] + dp[i - 1][j - costs[i - 1]]);
        }
    }

    auto answer = dp[parties][budget];

    int index = 0;
    for (int j = 0; j <= budget; j++)
    {
        if (dp[parties][j] == answer)
        {
            index = j;
            break;
        }
    }

    for (int i = 0; i < parties + 1; i++)
        dp[i].clear();
    dp.clear();

    return std::make_pair(index, answer);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int budget, parties;

    while (true)
    {
        cin >> budget >> parties;
        if (budget == 0 && parties == 0)
            break;

        vector<int> fun(parties);
        vector<int> costs(parties);

        for (int i = 0; i < parties; i++)
            cin >> costs[i] >> fun[i];

        auto my_pair = party_problem(fun, costs, parties, budget);

        cout << my_pair.first << " " << my_pair.second << endl;
    }
}

// // Sample IO
// 50 10
// 12 3
// 15 8
// 16 9
// 16 6
// 10 2
// 21 9
// 18 4
// 12 4
// 17 8
// 18 9

// 50 10
// 13 8
// 19 10
// 16 8
// 12 9
// 10 2
// 12 8
// 13 5
// 15 5
// 11 7
// 16 2

// 0 0