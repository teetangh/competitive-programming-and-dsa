#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

pair<int, int> min_num_of_insertions_deletions(string X, string Y)
{
    int default_value = 0;
    vector<vector<int>> tabulation_matrix;
    tabulation_matrix.resize(X.length() + 1, vector<int>(Y.length() + 1, default_value));

    for (int i = 1; i < X.length() + 1; i++)
    {
        for (int j = 1; j < Y.length() + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                tabulation_matrix[i][j] = 1 + tabulation_matrix[i - 1][j - 1];
            else
                tabulation_matrix[i][j] = max(tabulation_matrix[i - 1][j], tabulation_matrix[i][j - 1]);
        }
    }

    int longest_common_subsequence_length = tabulation_matrix[X.length()][Y.length()];

    int deletions = X.length() - longest_common_subsequence_length;
    int insertions = Y.length() - longest_common_subsequence_length;

    return std::make_pair(deletions, insertions);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    while (test_cases--)
    {
        string X, Y;
        cin >> X >> Y;
        cout << min_num_of_insertions_deletions(X, Y).first << " "
             << min_num_of_insertions_deletions(X, Y).second;
    }
}
