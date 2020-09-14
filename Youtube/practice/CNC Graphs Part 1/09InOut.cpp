int timer = 1;

bool dfs(int v)
{
    vis[v] = 1;
    in[v] = timer++;

    for (int child : ar[v])
    {
        if (!vis[child])
            dfs(child);
    }

    out[v] = timer++;
}