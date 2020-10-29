#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int row, int col)
{
    vector<vector<int>> dp;
    dp.resize(row, vector<int>(col, 0));

    for (int j = 0; j < col; j++)
        dp[0][j] = arr[0][j] ^ 1;

    for (int i = 0; i < row; i++)
        dp[i][0] = arr[i][0] ^ 1;

    int maxSubMatrix = INT_MIN;
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (arr[i][j] == 0)
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            else
                dp[i][j] = 0;

            if (dp[i][j] > maxSubMatrix)
                maxSubMatrix = dp[i][j];
        }
    }

    // for(int i = 0 ; i < row ; i++)
    // {
    // for(int j = 0 ; j < col ; j++)
    // {
    // cout << dp[i][j] << " ";
    // }
    // 	cout << endl;
    // }
    return maxSubMatrix;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];
    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
    delete arr;
    return 0;
}