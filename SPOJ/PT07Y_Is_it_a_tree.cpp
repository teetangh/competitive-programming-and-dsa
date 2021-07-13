// Includes
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX (int)(10e6 + 1)

vector<int> ar[MAX];
int vis[MAX];

bool dfs(int node, int parent)
{
    vis[node] = 1;

    for (auto child : ar[node])
    {
        if (!vis[child])
        {
            bool ans = dfs(child, node);
            if (ans == false)
                return false;
        }
        else if (vis[node] && child != parent)
            return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int N, M;
    cin >> N >> M;

    int u, v;
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }

    bool ans = dfs(1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
            ans = false;
    }

    if (ans == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
