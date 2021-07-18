// O(2^N)
int stairs(int N)
{
    if (N == 1 || N == 2)
        return N;

    int result = 0;

    // Calculating on subproblems for N - 1 and N - 2
    result += stairs(N - 1) + stairs(N - 2);

    return result;
}

// DP Solution
#define MAX 1000001
int dp[MAX];

int stairs(int N)
{
    if (N == 1 || N == 2)
        return N;

    if (dp[N] != -1)
        return dp[N];

    dp[N] = stairs(N - 1) + stairs(N - 2);
    return dp[N];
}