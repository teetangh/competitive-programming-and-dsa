int timer = 1;

bool dfs(int v)
{
    vis[v] = 1;
    in[v] = timer++;

    for (auto child : ar[child])
    {
        if (!vis[child])
            dfs(child)
    }
    out[v] = timer++;
}