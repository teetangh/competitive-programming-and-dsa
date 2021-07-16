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

int maxD, maxNode;

void dfs(int node, int d)
{
    vis[node] = 1;
    if (d > maxD)
        maxD = d, maxNode = node;

    for (auto child : ar[node])
    {
        if (!vis[child])
            dfs(child, d + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    int n, a, b;
    cin >> n;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    maxD = -1;
    dfs(1, 0);

    // A tree is a graph with n nodes/vertices has n-1 edges
    for (int i = 0; i <= n; i++)
        vis[i] = 0;

    maxD = -1;
    dfs(maxNode, 0);

    cout << maxD << endl;
}
