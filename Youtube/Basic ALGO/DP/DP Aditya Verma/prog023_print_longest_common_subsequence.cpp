#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string print_longest_common_subsequence(string X, string Y)
{
    int default_value = 0;
    vector<vector<int>> tabulation_matrix;
    tabulation_matrix.resize(X.length() + 1, vector<int>(Y.length() + 1, default_value));

    int i, j;
    for (i = 1; i < X.length() + 1; i++)
    {
        for (j = 1; j < Y.length() + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                tabulation_matrix[i][j] = 1 + tabulation_matrix[i - 1][j - 1];
            else
                tabulation_matrix[i][j] = max(tabulation_matrix[i - 1][j], tabulation_matrix[i][j - 1]);
        }
    }

    int longest_common_subseqence_length = tabulation_matrix[X.length()][Y.length()];
    cout << longest_common_subseqence_length << " ";

    std::string longest_common_subseqence_string;
    i = X.length();
    j = Y.length();
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            longest_common_subseqence_string.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (tabulation_matrix[i - 1][j] > tabulation_matrix[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(longest_common_subseqence_string.begin(), longest_common_subseqence_string.end());
    return longest_common_subseqence_string;
}
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
