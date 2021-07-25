#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int reach_score(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i] + dp[i - 3];

    for (int i = 5; i <= n; i++)
        dp[i] = dp[i] + dp[i - 5];

    for (int i = 10; i <= n; i++)
        dp[i] = dp[i] + dp[i - 10];

    return dp[n];
}
int main()
{
    //code
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << reach_score(n) << endl;
    }
    return 0;
}
// Example:
// Input:
// 3
// 8
// 20
// 13

// Output:
// 1
// 4
// 2

// Explanation
// For 1st example when n = 8
// { 3, 5 } and {5, 3} are the two possible permutations but these represent the same cobmination. Hence output is 1.