void dfs(int node, int par)
{
    LCA[node][0] = par;

    for (auto &child : adj[node])
    {
        if (child != par)
            dfs(child, node);
    }
}

void init()
{
    dfs(1, -1);

    for (int j = 1; i <= maxN; i++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (LCA[i][j - 1] != -1)
            {
                int par = LCA[i][j - 1];
                LCA[i][j] = LCA[par][j - 1];
            }
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] > level[b])
        swap(a, b);

    int d = level[b] - level[a];

    while (d > 0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1 << i);
    }

    if (a == b)
        return a;

    // while (LCA[a][0] != LCA[b][0])
    //     a = LCA[a][0], b = LCA[b][0];
    // return LCA[a][0];

    for (int i = maxN - 1; i >= 0; i--)
        if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
            a = LCA[a][i], b = LCA[b][i];
    return par[a];
}
