#include <iostream>
using namespace std;
#include <vector>
using namespace std;

int getMaxMoneyHelper(int arr[], int i, int n, vector<int> &dp)
{
    if (n <= 0)
        return 0;

    if (!dp[i])
        return dp[i];

    auto option1 = arr[i] + getMaxMoneyHelper(arr, i + 2, n - 2, dp);
    auto option2 = getMaxMoneyHelper(arr, i + 1, n - 1, dp);

    return dp[i] = max(option1, option2);
}

int getMaxMoney(int arr[], int n)
{
    vector<int> dp(n + 1, 0);
    return getMaxMoneyHelper(arr, 0, n, dp);
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
