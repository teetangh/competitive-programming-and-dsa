// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX 1000001
vector<int> ar[MAX];
int visited[MAX];
int colors[MAX];

bool dfs(int node, int color)
{
    visited[node] = 1;
    colors[node] = color;

    for (auto child : ar[node])
    {
        if (!visited[child])
        {
            if (dfs(child, color ^ 1) == false)
                return false;
        }
        else if (colors[child] == colors[node])
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

    int t;
    cin >> t;

    int N, M;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> N >> M;
        int u, v;

        for (int i = 0; i < MAX; i++)
            ar[i].clear();

        for (int i = 0; i < MAX; i++)
            visited[i] = 0, colors[i] = 0;

        for (int i = 1; i <= M; i++)
        {
            cin >> u >> v;
            ar[u].push_back(v);
            ar[v].push_back(u);
        }

        bool ans = true;
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
                ans = dfs(i, 0);

            if (ans == false)
                break;
        }

        cout << "Scenario #" << tc << ":" << endl;
        if (ans)
            cout << "No suspicious bugs found!" << endl;
        else
            cout << "Suspicious bugs found!" << endl;
    }
}
