// Two X n Tiling Problem

int prog03TwoXnTiling(int N)
{
    if (N == 1)
        return 1;
    else if (N == 2)
        return 2;

    int *dp = new int[N];
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[N - 1];
}