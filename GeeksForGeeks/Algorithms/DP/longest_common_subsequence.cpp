#include <bits/stdc++.h>

using namespace std;

int lcs_length(string X, string Y)
{
    vector<vector<int>> dp;
    dp.resize(X.length() + 1, vector<int>(Y.length() + 1, 0));

    for (int i = 1; i < X.length() + 1; i++)
    {
        for (int j = 1; j < Y.length() + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[X.length()][Y.length()];
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        string X, Y;
        int n1, n2;
        cin >> n1 >> n2;
        cin >> X >> Y;
        cout << lcs_length(X, Y) << endl;
    }

    return 0;
}
// Example:
// Input:
// 2
// 6 6
// ABCDGH
// AEDFHR
// 3 2
// ABC
// AC

// Output:
// 3
// 2

// Explanation
// LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

// LCS of "ABC" and "AC" is "AC" of length 2
 