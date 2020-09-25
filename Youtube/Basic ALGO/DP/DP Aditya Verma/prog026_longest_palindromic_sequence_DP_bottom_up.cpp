#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
#include "include/header003_longest_common_subsequence.hpp"

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    while (test_cases--)
    {
        string X;
        cin >> X;

        string X_reverse(X);
        reverse(X.begin(), X.end());

        cout << print_longest_common_subsequence(X, X_reverse);
    }
}
// Sample IO
// 1
// agbcba

// 5 abcba