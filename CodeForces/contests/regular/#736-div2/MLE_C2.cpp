// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 200001

int adj[MAX][MAX];
int backup[MAX][MAX];

void printMatrix(int v, int adj[][MAX])
{
    for (int i = 0; i <= v; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int countRemaining(int v, int adj[][MAX])
{
    int count = 0;
    // for (int i = 1; i <= v; i++)
    // {
    //     bool alive = false;
    //     for (int j = 1; j <= v; j++)
    //         if (adj[i][j] == 1)
    //         {
    //             alive = true;
    //             break;
    //         }

    //     if (alive)
    //         count++;
    // }

    for (int i = 1; i <= v; i++)
        if (adj[i][0] == 1)
            count++;
    return count;
}

void addEdge(int adj[][MAX], int a, int b)
{
    adj[a][0] = 1;
    adj[b][0] = 1;

    adj[a][b] = 1;
    adj[b][a] = 1;
}

void removeEdge(int adj[][MAX], int a, int b)
{
    adj[a][b] = 0;
    adj[b][a] = 0;
}
void killNode(int v, int adj[][MAX], int node)
{
    adj[node][0] = 0;
    for (int i = 0; i <= v; i++)
        removeEdge(adj, node, i);
}
void attackVulnerable(int v, int adj[][MAX])
{
    for (int i = 1; i <= v; i++)
    {
        bool isVulnerable = true;
        for (int j = 1; j < i; j++)
            if (adj[i][j] == 1)
            {
                isVulnerable = false;
                break;
            }

        if (isVulnerable)
            for (int j = i + 1; j <= v; j++)
                if (adj[i][j] == 1)
                {
                    // removeEdge(adj, i, j);
                    killNode(v, adj, i);
                    break;
                }
    }
}

void restoreBackup(int v, int adj[][MAX], int backup[][MAX])
{
    for (int i = 0; i <= v; i++)
        for (int j = 0; j <= v; j++)
            adj[i][j] = backup[i][j];
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

    // int **adj = new int *[v + 1];
    for (int i = 0; i <= v; i++)
    {
        // adj[i] = new int[v + 1];
        adj[i][0] = 1;
    }

    // int **backup = new int *[v + 1];
    for (int i = 0; i <= v; i++)
    {
        // backup[i] = new int[v + 1];
        backup[i][0] = 1;
    }

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
        attackVulnerable(v, adj);
        cin >> q;
        // printMatrix(v , adj, v);
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
            cout << countRemaining(v, adj) << endl;
            break;
        }
        restoreBackup(v, adj, backup);
    }

    return 0;
}
