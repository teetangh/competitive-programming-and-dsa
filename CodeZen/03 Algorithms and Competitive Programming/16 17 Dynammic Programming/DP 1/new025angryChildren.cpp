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

    int N, K;
    cin >> N >> K;

    vector<int> packets(1 + N, 0);
    for (int i = 0; i < N; i++)
        cin >> packets[i];

    sort(packets.begin(), packets.end());

    auto dp(packets);
    // vector<int> dp(1 + N, 0);

    // dp[0] = 0;
    // dp[1] = abs(packets[1] - packets[0]);
    int target = abs(packets[1] - packets[0]);
    int cum_sum = packets[0] + packets[1];

    // Sliding windows (of size K ) approach
    for (int i = 2; i < K; i++)
    {
        // Mods are positive since the packets are sorted
        target += (i * packets[i]) - cum_sum;
        // Calculating the cumulative sum of the packets so far
        cum_sum += packets[i];
    }
    cum_sum -= packets[0];

    dp[K] = target;
    for (int i = K + 1; i < N; i++)
    {
        // dp[i] = dp[i - 1] + ((K - 1) * (packets[i - K + 1] + packets[K + i ])) - 2 * (cum_sum);
        // cum_sum = cum_sum - packets[i - K] + packets[K + i];

        dp[i] = dp[i - 1] + ((K - 1) * (packets[i]))
    }

    for (auto &elem : dp)
    {
        cout << elem << " ";
    }
    cout << endl;

    int min_abs_diff = INT_MAX;
    for (int i = K; i < N; i++)
    {
        if (dp[i] < min_abs_diff)
            min_abs_diff = dp[i];
    }

    cout << min_abs_diff << endl;
}
