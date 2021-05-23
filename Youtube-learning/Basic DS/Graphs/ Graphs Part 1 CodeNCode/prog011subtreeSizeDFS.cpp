int dfs(int node)
{
    vis[node] = 1;
    int curr_size = 1;

    for (int child : adj[node])
    {
        if (!vis[child])
            curr_size += dfs(child);
    }

    subSize[node] = curr_size;
    return curr_size;
}y 