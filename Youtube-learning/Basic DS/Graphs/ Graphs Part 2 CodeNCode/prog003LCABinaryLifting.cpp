// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100000

const int maxNlevels = (int)log2(MAX);

vector<int> level(maxNlevels + 1,-1);
vector<int> parent(MAX,-1);
vector<int> adj[MAX];
vector<vector<int>> dp(MAX, vector<int>(maxNlevels, -1));

int LCA(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);

    int d = level[b] - level[a];

    // Decrease the depth difference in logarithmic/binary search way rather than linearly
    while (d > 0)
    {
        int i = log2(d);
        b = dp[b][i];
        d -= (1 << i);
    }

    // If they reach the same node
    if (a == b)
        return a;

    // while (dp[a][0] != dp[b][0])
    //     a = dp[a][0], b = dp[b][0];  
    // return dp[a][0];


    // Once they are at the same level, make the highest possible jump to reach the LCA 
    // but one depth less or else we wont be able to distinguish 
    for (int i = maxNlevels - 1; i >= 0; i--)
        if (dp[a][i] != -1 && (dp[a][i] != dp[b][i]))
            a = dp[a][i], b = dp[b][i];

    // Return the answer of one depth up
    return parent[a];
}

void dfs(int node, int parent)
{
    dp[node][0] = parent;

    for (auto &child : adj[node])
    {
        if (child != parent)
            dfs(child, node);
    }
}

void init()
{
    dfs(1, -1);

    for (int j = 1; j <= maxNlevels; j++)
    {
        for (int i = 1; i <= MAX; i++)
        {
            if (dp[i][j - 1] != -1)
            {
                int parent = dp[i][j - 1];
                dp[i][j] = dp[parent][j - 1];
            }
        }
    }
}