// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    enum matchTypes
    {
        fullMatch = 0,
        partialMatch = 1,
    };

public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        int n = pattern.size();
        int m = str.size();
        int dp[n + 1][m + 1];
        int matchType = fullMatch;

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;

                if (i == 0 && j > 0)
                    dp[i][j] = matchType;

                if (j == 0 && i > 0)
                {
                    if (pattern[i - 1] == '*' && dp[i - 1][j] == 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                auto currentChar = pattern[i - 1];
                if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
                {
                    if (currentChar == str[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = 0;
                }
                else if (currentChar == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (currentChar == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        // cout << "DP MATRIX " << endl;
        // for (int i = 0; i < n + 1; i++)
        // {
        //     for (int j = 0; j < m + 1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}
// } Driver Code Ends

// // Sample IO
// 3

// ****a***b**c
// dsfsabc

// ba*a?
// baaabab

// a*ab
// baaabab

// 1
// 1
// 0
