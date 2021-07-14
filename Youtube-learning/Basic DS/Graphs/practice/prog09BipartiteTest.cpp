bool dfs(int v, int c)
{
    vis[v] = 1;
    col[v] = c;

    for (auto child : ar[v])
    {
        if (vis[child] == 0)
        {
            // Exor operation to alternate between colors
            if (dfs(child, c ^ 1) == false)
                return false;
        }
        // Two adjacent nodes cant have same color
        else if (col[v] == col[child])
            return false;
    }
    return true;
}