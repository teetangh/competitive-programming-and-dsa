void dfs(int v)
{
    vis[v] = 1;
    cout << v << " -> ";

    for (auto child : ar[v])
    {
        if (vis[child] == 0)
            dfs(child);
    }
}

int main(int argc, char const *argv[])
{
    int cc_count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i), cc_count++;
    }

    cout << cc_count;

    return 0;
}
