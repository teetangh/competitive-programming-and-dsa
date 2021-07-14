int main(int argc, char const *argv[])
{
    // ...

    int cc_count = 0;

    for (int i = 1; i < <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i), cc_count++;
    }

    cout << cc_count << endl;

    return 0;
}
