#include <iostream>
using namespace std;
// #include "solution.h"
using namespace std;

int getMaxMoney(int arr[], int n)
{
    int *dp = (int *)calloc(n, sizeof(int));

    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for (int i = 2; i < n; i++)
    {
        auto option1 = arr[i] + dp[i - 2];
        auto option2 = dp[i - 1];
        dp[i] = max(option1, option2);
    }

    auto answer = dp[n - 1];
    delete[] dp;
    return answer;
}

int main()
{
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}
