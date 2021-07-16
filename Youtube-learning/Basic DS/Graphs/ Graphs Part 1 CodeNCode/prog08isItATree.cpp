// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX 10001
vector<int> ar[MAX];
int vis[MAX];

void dfs(int node)
{
    vis[node] = 1;

    for (auto child : ar[node])
    {
        if (!vis[child])
            dfs(child);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    int cc_count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] == 0)
            dfs(i), cc_count++;
    }

    if (cc_count == 1 && m == n - 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
