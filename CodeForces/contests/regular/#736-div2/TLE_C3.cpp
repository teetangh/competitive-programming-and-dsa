#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, set<int>> adj;
unordered_map<int, set<int>> backup;

void printMatrix(unordered_map<int, set<int>> &adj, int v)
{
    cout << "==================\n";
    for (auto nodeList : adj)
    {
        cout << nodeList.first << "->";
        for (auto ele : nodeList.second)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "==================\n";
}

int countRemaining(unordered_map<int, set<int>> &adj, int v)
{
    int count = 0;
    for (auto nodeList : adj)
    {
        // if (!nodeList.second.empty())
        count++;
    }
    return count;
}

void addEdge(unordered_map<int, set<int>> &adj, int a, int b)
{
    adj[a].insert(b);
    adj[b].insert(a);
}

void removeEdge(unordered_map<int, set<int>> &adj, int a, int b)
{
    auto it = std::find(adj[a].begin(), adj[a].end(), b);
    if (it != adj[a].end())
        adj[a].erase(it);

    // auto it2 = std::find(adj[b].begin(), adj[b].end(), a);
    // if (it2 != adj[b].end())
    //     adj[b].erase(it2);
}

void killNode(unordered_map<int, set<int>> &adj, int node)
{
    for (auto ele : adj[node])
        removeEdge(adj, ele, node);
    adj.erase(node);
}

bool attackVulnerable(unordered_map<int, set<int>> &adj, int v)
{
    bool changed = false;
    // for (auto ele : adj)
    for (int i = 1; i <= v; i++)
    {
        bool isVulnerable = true;
        if (adj[i].empty() || adj[i].lower_bound(1) != adj[i].upper_bound(i))
            isVulnerable = false;

        if (isVulnerable)
        {
            killNode(adj, i);
            changed = true;
        }
    }

    return changed;
}

void restoreBackup(unordered_map<int, set<int>> &adj, unordered_map<int, set<int>> backup)
{
    adj.clear();
    adj.insert(backup.begin(), backup.end());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    int v, e, a, b;
    cin >> v >> e;

    for (int i = 1; i <= e; i++)
    {
        cin >> a >> b;
        addEdge(adj, a, b);
        addEdge(backup, a, b);
    }

    int Q, q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        printMatrix(adj, v);
        attackVulnerable(adj, v);
        cin >> q;
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

            removeEdge(adj, b, a);
            removeEdge(backup, b, a);
            break;

        case 3:
            // printMatrix(adj, v);
            cout << countRemaining(adj, v) << endl;
            break;
        }

        restoreBackup(adj, backup);
    }
    return 0;
}
