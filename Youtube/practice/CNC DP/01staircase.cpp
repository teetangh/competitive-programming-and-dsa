int dp[1000001];
int mod = 1e9 + 7;

void init()
{
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
}