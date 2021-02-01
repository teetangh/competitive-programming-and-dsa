// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int max_profit(const vector<int> &stocks)
{
    int current_profit = 0;
    int max_profit = 0;

    int buy_day = 0;
    for (int i = 1; i < stocks.size(); i++)
    {
        if(stocks[i] >= stocks[i-1])
            continue;

        


    }
    

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
        int days;
        cin >> days;

        vector<int> stocks(days);
        for (int i = 0; i < days; i++)
            cin >> stocks[i];

        cout << max_profit(stocks) << endl;
        stocks.clear();
    }
}
