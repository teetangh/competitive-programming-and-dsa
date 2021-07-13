#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
#define pb push_back;

vector<int> ar[MAX];
int visited[MAX];

void dfs(int node)
{
    visited[node] = 1;

    for (auto child : ar[node])
    {
        if (!visited[child])
            dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < MAX; i++)
        ar[i].clear();

    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }

    int cc_count = 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i), cc_count++;

    cout << cc_count << endl;
}
