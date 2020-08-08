#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int longest_common_subsequence(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    else if (X[m - 1] == Y[n - 1])
        return 1 + longest_common_subsequence(X, Y, m - 1, n - 1);
    else
        return max(longest_common_subsequence(X, Y, m, n - 1), longest_common_subsequence(X, Y, m - 1, n));
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif
    string X, Y;
    cin >> X >> Y;
    int answer = longest_common_subsequence(X, Y, X.length(), Y.length());
    cout << answer;
    return 0;
    return 0;
}

// // Sample IO
// batman

// aman

// 4