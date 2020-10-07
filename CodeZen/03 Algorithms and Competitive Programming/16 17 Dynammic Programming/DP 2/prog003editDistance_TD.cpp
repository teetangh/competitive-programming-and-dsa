// #include "Solution.h"
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int editDistanceRecursionHelper(string s1, string s2, vector<vector<int>> &dp)
{
    if (s1.length() == 0)
        return s2.length();
    if (s2.length() == 0)
        return s1.length();

    if (dp[s1.length()][s2.length()] > -1)
        return dp[s1.length()][s2.length()];

    if (s1[0] == s2[0])
        return dp[s1.length()][s2.length()] = editDistanceRecursionHelper(s1.substr(1), s2.substr(1), dp);
    else
        return dp[s1.length()][s2.length()] = 1 + min(min(editDistanceRecursionHelper(s1, s2.substr(1), dp),
                                                          editDistanceRecursionHelper(s1.substr(1), s2, dp)),
                                                      editDistanceRecursionHelper(s1.substr(1), s2.substr(1), dp));
}

int editDistance(string s1, string s2)
{
    int default_value = -1;
    vector<vector<int>> dp;
    dp.resize(s1.length() + 1, vector<int>(s2.length() + 1, default_value));

    return editDistanceRecursionHelper(s1, s2, dp);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}
