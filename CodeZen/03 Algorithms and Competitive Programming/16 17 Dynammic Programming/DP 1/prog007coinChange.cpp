#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// #include "Solution.h"

int countWaysToMakeChangeHelper(int denominations[], int numDenominations, int value, vector<vector<int>> &dp)
{
    if (value == 0)
        return dp[value][numDenominations] = 1;

    if (value < 0)
        return 0;

    if (numDenominations == 0)
        return dp[value][numDenominations] = 0;

    if (dp[value][numDenominations] > -1)
        return dp[value][numDenominations];

    int first = countWaysToMakeChangeHelper(denominations, numDenominations, value - denominations[0], dp);
    int second = countWaysToMakeChangeHelper(denominations + 1, numDenominations - 1, value, dp);

    return dp[value][numDenominations] = first + second;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int default_value = -1;
    vector<vector<int>> dp;
    dp.resize(value + 1, vector<int>(numDenominations + 1, default_value));

    for (int i = 0; i < value + 1; i++)
    {
        for (int j = 0; j < numDenominations + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    return countWaysToMakeChangeHelper(denominations, numDenominations, value, dp);
}

int main()
{

    int numDenominations;
    cin >> numDenominations;
    int *denominations = new int[numDenominations];
    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }
    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);
}
// Sample Input 1 :
// 3
// 1 2 3
// 4
// Sample Output
// 4
// Sample Output Explanation :
// Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).