// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define MAX 100001
vector<int> ar[MAX];

int in[MAX];
int visited[MAX];
int low[MAX];
int timer;

void dfs(int node, int par)
{
    visited[node] = 1;
    in[node] = low[node] = timer++;

    for (auto child : ar[node])
    {
        if (child == par)
            continue;

        else if (visited[child] == true)
        {
            // edge {node-child} is a back-edge
            low[node] = min(low[node], in[child]);
        }
        else
        {
            // edge {node-child} is a forward-edge
            dfs(child, node);

            // There is no (ancestor of child/parent of node) connected to child
            // hence upon removing (node-child) bridge, the child would be disconnected
            if (in[node] < low[child])
                cout << node << " -> " << child << " is a bridge " << endl;

            // Since if a child can reach this minimum, the parent node can also reach this minimum
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin); // for getting input from xinput.txt
#endif

    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
    fastio;

    int n, m, x, y;
    cin >> n >> m;

    while (m--)
    {
        cin >> x >> y;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }

    dfs(1, -1);
}

// // Sample IO 1
// 4 4
// 1 2
// 2 3
// 2 4
// 3 4

// 1 -> 2 is a bridge

// // Sample IO 2
// 4 3
// 1 2
// 1 3
// 1 4

// 1 -> 2 is a bridge
// 1 -> 3 is a bridge
// 1 -> 4 is a bridge
