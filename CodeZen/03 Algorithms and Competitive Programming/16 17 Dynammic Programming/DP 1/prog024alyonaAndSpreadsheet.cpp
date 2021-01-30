// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> spreadsheet;
    spreadsheet.resize(n, vector<int>(m, 0));

    auto dp(spreadsheet);

    // Store in the 2d DP array how column elements increase up to that element
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> spreadsheet[i][j];

            if (i == 0)
                dp[0][j] = 1;
            else
            {
                if (spreadsheet[i][j] >= spreadsheet[i - 1][j])
                    dp[i][j] = dp[i - 1][j] + 1;
                else
                    dp[i][j] = 1;
            }
        }
    }

    int k;
    cin >> k;

    // Calculate if even one column has the necessary non-decreasing sort.
    while (k--)
    {
        int l, r;
        cin >> l >> r;

        bool flag = false;
        for (int j = 0; j < m; j++)
        {
            if (dp[r - 1][j] >= (r - l + 1))
                flag = true;
            else
                continue;
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

// Sample Input
// 5 4
// 1 2 3 5
// 3 1 3 2
// 4 5 2 3
// 5 5 3 2
// 4 4 3 4
// 6
// 1 1
// 2 5
// 4 5
// 3 5
// 1 3
// 1 5
// Sample Output
// Yes
// No
// Yes
// Yes
// Yes
// No