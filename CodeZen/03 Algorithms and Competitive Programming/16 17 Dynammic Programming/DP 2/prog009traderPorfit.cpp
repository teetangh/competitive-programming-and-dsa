// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int max_profit(int *stocks, int days, int transactions, int ongoing, vector<vector<vector<int>>> &dp)
{
    if (days == 0 || transactions == 0)
        return 0;

    if (dp[days][transactions][ongoing] > 0)
        return dp[days][transactions][ongoing];

    int option1 = INT_MIN, option2 = INT_MIN, option3 = INT_MIN, option4 = INT_MIN;

    if (ongoing)
        option1 = max_profit(stocks + 1, days - 1, transactions - 1, 0, dp) + stocks[0];
    else
    {
        if (transactions > 0)
            option2 = max_profit(stocks + 1, days - 1, transactions, 1, dp) - stocks[0];
        else
            option3 = max_profit(stocks + 1, days - 1, 0, 0, dp);
    }

    option4 = max_profit(stocks + 1, days - 1, transactions, ongoing, dp);

    // cout << " option1 " << option1 << endl;
    // cout << " option2 " << option2 << endl;
    // cout << " option3 " << option3 << endl;
    // cout << " option4 " << option4 << endl;

    return dp[days][transactions][ongoing] = max(option1, max(option2, max(option3, option4)));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int q;
    cin >> q;
    // cout << q;

    while (q--)
    {
        int transactions, days;
        cin >> transactions >> days;

        // vector<int> stocks(days, 0);
        int *stocks = new int[days];

        vector<vector<vector<int>>> dp;
        dp.resize(days + 1, vector<vector<int>>(transactions + 1, vector<int>(2, 0)));

        for (int i = 0; i < days; i++)
            cin >> stocks[i];

        cout << max_profit(stocks, days, transactions, 0, dp) << endl;

        delete[] stocks;
    }
}
