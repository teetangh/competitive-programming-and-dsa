int dfs(int node)
{
    vis[node] = 1;
    int curr_size = 1;

    for (auto child : ar[node])
    {
        if (!vis[child])
            curr_size += dfs(child);
    }

    return subSize[node] = curr_size;
}