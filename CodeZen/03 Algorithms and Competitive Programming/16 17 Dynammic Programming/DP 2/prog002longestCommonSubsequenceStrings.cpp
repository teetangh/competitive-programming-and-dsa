#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"

#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int lcsHelper(string s1, string s2, vector<vector<int>> &dp)
{
    if (s1.length() == 0 || s2.length() == 0)
        return dp[s1.length()][s2.length()] = 0;

    if (dp[s1.length()][s2.length()] > -1)
        return dp[s1.length()][s2.length()];

    if (s1[0] == s2[0])
        return dp[s1.length()][s2.length()] = 1 + lcsHelper(s1.substr(1), s2.substr(1), dp);
    else
        return dp[s1.length()][s2.length()] = max(lcsHelper(s1, s2.substr(1), dp), lcsHelper(s1.substr(1), s2, dp));
}

int lcs(string s1, string s2)
{
    int default_value = -1;
    vector<vector<int>> dp;
    dp.resize(s1.length() + 1, vector<int>(s2.length() + 1, default_value));

    return lcsHelper(s1, s2, dp);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
}
// // Sample IO
// abcdefg
// b1d3ffg
// 4