int parent[10000];

// Iterative
int find(int n)
{
    while (1)
    {
        if (n == parent[n])
            return n;
        else
            n = parent[n];
    }
}

// recursive
int find(int n)
{
    if (n == parent[n])
        return n;
    else
        return find(parent[n]);
}