// Novice Approach

int LCA(int a, int b)
{
    if (level[b] < level[a])
        swap(a, b);
        
    int d = level[b] - level[a];

    while (d > 0)
    {
        b = par[b];
        d--;
    }

    if (a == b)
        return a;

    while (par[a] != par[b])
        a = par[a], b = par[b];

    return par[a];
}