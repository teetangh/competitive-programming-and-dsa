// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int distinct_subsequences(const string &str, vector<vector<int>> &p)
{
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        string str;
        getline(cin, str);

        vector<vector<int>> dp;
        dp.resize(str.length() + 1, vector<int>(str.length() + 1));

        cout << distinct_subsequences(str, dp) << endl;
    }
}
