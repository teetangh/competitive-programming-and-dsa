#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>

#include "include/header003_longest_common_subsequence.hpp"

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string X, Y;
        cin >> X >> Y;
        cout << print_longest_common_subsequence(X, Y) << endl;
    }

    return 0;
}
// // Sample IO
// 2
// ABCDGH AEDFHR
// AGGTAB GXTXAYB

// 3 ADH
// 4 GTAB
