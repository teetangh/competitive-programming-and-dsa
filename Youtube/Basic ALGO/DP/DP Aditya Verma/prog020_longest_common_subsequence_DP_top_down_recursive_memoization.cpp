#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int longest_common_subsequence(string X, string Y, int m, int n, vector<vector<int>> memoization_matrix)
{
    if (m == 0 || n == 0)
        return 0;

    if (memoization_matrix[m][n] != -1)
        return memoization_matrix[m][n];

    else if (X[m - 1] == Y[n - 1])
        return memoization_matrix[m][n] = 1 + longest_common_subsequence(X, Y, m - 1, n - 1, memoization_matrix);
    else
        return memoization_matrix[m][n] = max(longest_common_subsequence(X, Y, m, n - 1, memoization_matrix), longest_common_subsequence(X, Y, m - 1, n, memoization_matrix));
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    string X, Y;
    cin >> X >> Y;

    int default_value = -1;
    vector<vector<int>> memoization_matrix;
    memoization_matrix.resize(X.length() + 1, vector<int>(Y.length() + 1, default_value));

    int answer = longest_common_subsequence(X, Y, X.length(), Y.length(), memoization_matrix);
    cout << answer;
    return 0;
    return 0;
}

// // Sample IO
// batman

// aman

// 4