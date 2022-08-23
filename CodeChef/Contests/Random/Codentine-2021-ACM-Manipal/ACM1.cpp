// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool isValid(vector<vector<int>> arr, int i, int j)
{
    if (i < 0 || i > arr.size() - 1)
        return false;

    if (j < 0 || j > arr[i].size() - 1)
        return false;

    if (arr[i][j] == 0)
        return false;

    return true;
}

void dfs(vector<vector<int>> arr, int i, int j)
{
    
}

void solve(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
        }
    }
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

    while (tc--)
    {
        int m, n, temp;
        cin >> m >> n;

        vector<vector<int>> arr(m, vector<int>(n, 0));
        int count1 = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> temp;
                if (temp == 1)
                    count1++;
                arr[i][j] = temp;
            }
        }

        arr.clear();
    }
}
