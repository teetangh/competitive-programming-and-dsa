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

vector<int> spiralOrder(const vector<vector<int>> &A)
{

    vector<int> result;

    int row = A.size();
    int col = A[0].size();

    int limit = row * col;

    int rs = 0;
    int re = row - 1;

    int cs = 0;
    int ce = col - 1;

    int count = 0;
    int i, j;

    while (count < limit)
    {
        for (i = rs, j = cs; j <= ce; j++)
        {
            if (count == limit)
                break;
            result.push_back(A[i][j]);
            count++;
        }
        rs++;

        for (i = rs, j = ce; i <= re; i++)
        {
            if (count == limit)
                break;
            result.push_back(A[i][j]);
            count++;
        }
        ce--;

        for (i = re, j = ce; j >= cs; j--)
        {
            if (count == limit)
                break;
            result.push_back(A[i][j]);
            count++;
        }
        re--;

        for (i = re, j = cs; i >= rs; i--)
        {
            if (count == limit)
                break;
            result.push_back(A[i][j]);
            count++;
        }
        cs++;
    }

    return result;
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
        int m, n;
        cin >> m >> n;
        vector<vector<int>> A(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j; j < n; j++)
                cin >> A[i][j];
        }
        spiralOrder(A);
    }
}
