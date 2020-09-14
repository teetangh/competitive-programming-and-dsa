int stairs(int N)
{
    if (N == 1 || N == 2)
        return N;

    int res = 0;

    res += stairs(N - 1); // jumping 1 stair;
    res += stairs(N - 2); // jumping 2 stairs;

    return res;
}

int dp[1000001];

int stairs(int N)
{
    if (N <= 2)
        return N;

    if (dp[N] != -1)
        return dp[N];

    dp[N] = stairs(N - 1) + stairs(N - 2);
    return dp[N];
}