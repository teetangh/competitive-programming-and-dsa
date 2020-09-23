#include <iostream>
using namespace std;
// #include "solution.h"

long staircase(int n)
{
    long *dp = new long[n + 2];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (long i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    // return staircase(n-1) + staircase(n-2) + staircase(n-3);

    long answer = dp[n];
    delete[] dp;
    return answer;
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}
// Sample Input 1:
// 4
// Sample Output 1:
// 7