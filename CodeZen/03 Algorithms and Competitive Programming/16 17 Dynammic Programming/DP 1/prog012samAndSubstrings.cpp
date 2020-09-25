#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
long countArray(int n, int k, int x)
{
    //long dp[2][n];
    vector<vector<long>> dp;
    dp.resize(2, vector<long>(n, 0));
    auto MOD = 1000000007;
    if (x == 1)
    {
        dp[0][0] = 1;
        dp[1][0] = 0;
        dp[0][1] = 0;
        dp[1][1] = k - 1;
    }
    else
    {
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[1][0] = 1;
        dp[1][1] = k - 2;
    }
    for (int j = 2; j < n; j++)
    {
        dp[0][j] = dp[1][j - 1] % (MOD);
        dp[1][j] = (dp[0][j - 1] * (k - 1) + dp[1][j - 1] * (k - 2)) % (MOD);
    }
    return ((dp[0][n - 1]));
}

int substrings(string n)
{
    long MOD = 1000000007;

    vector<int> dp(n.length() + 1, 0);

    dp[0] = 0;

    for (int i = 1; i <= n.length(); i++)
    {
        dp[i] = (dp[i - 1] + ((dp[i - 1] * 10) + ((n[i - 1] - '0') * i))) % MOD;
        // cout << i << " " <<dp[i] << endl;
    }

    return dp[n.length()] % MOD;
}

// int substrings(string s)
// {
//     long long totalSum = s[0] - '0';
//     long long lastValue = s[0] - '0';

//     auto MOD = 1000000007;

//     for (int i =1; i < s.length() ;i++) {
//         lastValue =  lastValue*10 + ((s[i] - '0') * (i + 1));
//         lastValue = lastValue % MOD;

//         totalSum = (totalSum + lastValue) % MOD;

//         cout << lastValue << " " << totalSum << " " << endl;
//     }

//     return totalSum;

// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
