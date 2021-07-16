#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
vector<int> ar[MAX];

int in[MAX];
int visited[MAX];
int low[MAX];
int timer;

void dfs(int node, int par = -1)
{
    visited[node] = 1;
    in[node] = low[node] = timer++;

    int children = 0;

    for (auto child : ar[node])
    {
        if (child == par)
            continue;

        if (visited[child])
            low[node] = min(low[node], in[child]);

        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);

            if (low[child] >= in[node] && par != -1)
                IS_CUTPOINT(node);
            children++;
        }
    }

    if (par == -1 && children > 1)
        IS_CUTPOINT(node);
}