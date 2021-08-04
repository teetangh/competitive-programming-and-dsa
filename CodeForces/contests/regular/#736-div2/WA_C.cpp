// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 20000

vector<int> adj[MAX];
vector<int> backup[MAX];

int countRemaining(vector<int> adj[], int v)
{
    int count = 0;
    for (int i = 0; i < v; i++)
        for (auto ele : adj[i])
            count++;

    return count / 2;
}

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void removeEdge(vector<int> adj[], int a, int b)
{

    auto it = find(adj[a].begin(), adj[a].end(), b);
    if (it != adj[a].end())
        adj[a].erase(it);

    auto it2 = find(adj[b].begin(), adj[b].end(), a);
    if (it2 != adj[b].end())
        adj[b].erase(it2);
}

void killNode(vector<int> adj[], int node, int v)
{
    adj[node][0] = 0;
    for (int i = 0; i <= v; i++)
        removeEdge(adj, node, i);
}
void attackVulnerable(vector<int> adj[], int v)
{
}

void restoreBackup(vector<int> adj[], vector<int> backup[], int v)
{
    for (int i = 0; i < v; i++)
    {
        adj[i].clear();
        for (auto ele : backup[i])
            adj[i].push_back(ele);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int v, e, a, b;
    cin >> v >> e;

    for (int i = 1; i <= e; i++)
    {
        cin >> a >> b;
        addEdge(adj, a, b);
        addEdge(backup, a, b);
    }

    // int q;
    // cin >> q;

    // for (int i = 0; i < q; i++)
    // {
    //     cin >> q;
    //     switch (q)
    //     {
    //     case 1:
    //         cin >> a >> b;
    //         addEdge(adj, a, b);
    //         addEdge(backup, a, b);
    //         break;

    //     case 2:
    //         cin >> a >> b;
    //         removeEdge(adj, a, b);
    //         removeEdge(backup, a, b);
    //         break;

    //     case 3:
    //         cout << countRemaining(adj, v) << endl;
    //         break;
    //     }

    //     for (int i = 0; i < v; i++)
    //     {
    //         adj[i].clear();
    //         for (auto ele : backup[i])
    //             adj[i].push_back(ele);
    //     }
    // }
    int Q, q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        attackVulnerable(adj, v);
        cin >> q;
        // printMatrix(adj, v);
        switch (q)
        {
        case 1:
            cin >> a >> b;
            addEdge(adj, a, b);
            addEdge(backup, a, b);
            break;

        case 2:
            cin >> a >> b;
            removeEdge(adj, a, b);
            removeEdge(backup, a, b);
            break;

        case 3:
            cout << countRemaining(adj, v) << endl;
            break;
        }
        restoreBackup(adj, backup, v);
    }
}
