#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int getMin(int *arr, int n)
{

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            dp[i] = 1 + dp[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && dp[i] <= dp[i + 1])
            dp[i] = 1 + dp[i + 1];
    }

    int answer = accumulate(dp.begin(), dp.end(), 0);
    dp.clear();
    return answer;
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getMin(arr, n);
    delete[] arr;
}
