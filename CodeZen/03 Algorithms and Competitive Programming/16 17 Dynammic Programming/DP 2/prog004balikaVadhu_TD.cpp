#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long ll;
typedef long long int lli;

int balikaVadhuRecursionHelper(string s1, string s2, int K, vector<vector<vector<int>>> &dp)
{
    if (K == 0)
        return 0;

    if ((s1.length() == 0 || s2.length() == 0))
    {
        if (K > 0)
            return INT_MIN;
        else
            return 0;
    }

    if (dp[s1.length()][s2.length()][K] != -1)
        return dp[s1.length()][s2.length()][K];

    if (s1[0] == s2[0])
    {
        if (K > 0)
            return dp[s1.length()][s2.length()][K] = max(max(balikaVadhuRecursionHelper(s1.substr(1), s2, K, dp),
                                                             balikaVadhuRecursionHelper(s1, s2.substr(1), K, dp)),
                                                         int(s1[0]) + balikaVadhuRecursionHelper(s1.substr(1), s2.substr(1), K - 1, dp));
        else
            return 0;
    }

    else
        return dp[s1.length()][s2.length()][K] = max(balikaVadhuRecursionHelper(s1.substr(1), s2, K, dp), balikaVadhuRecursionHelper(s1, s2.substr(1), K, dp));
}

int balikaVadhu(string s1, string s2, int K)
{
    vector<vector<vector<int>>> dp;
    dp.resize(s1.length() + 1, vector<vector<int>>(s2.length() + 1, vector<int>(K + 1, -1)));

    for (int i = 0; i <= s1.length(); i++)
        for (int j = 0; j <= s2.length(); j++)
            dp[i][j][0] = 0;

    auto answer = balikaVadhuRecursionHelper(s1, s2, K, dp);
    return ((answer > 0) ? answer : 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string s1, s2;
        int K;
        cin >> s1 >> s2 >> K;
        // cout << s1 << s2 << K << endl;
        cout << balikaVadhu(s1, s2, K) << endl;
    }
    return 0;
}
