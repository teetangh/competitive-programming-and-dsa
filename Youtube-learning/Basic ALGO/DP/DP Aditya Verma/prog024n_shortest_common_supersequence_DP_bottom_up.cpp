#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

string print_shortest_common_supersequence(string X, string Y)
{
    int default_value = 0;
    std::vector<std::vector<int>> tabulation_matrix;
    tabulation_matrix.resize(X.length() + 1, std::vector<int>(Y.length() + 1));

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

    int longest_common_subsequence_length = tabulation_matrix[X.length()][Y.length()];
    std::string longest_common_subsequence_string;

    i = X.length();
    j = Y.length();
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            longest_common_subsequence_string.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (tabulation_matrix[i][j - 1] > tabulation_matrix[i - 1][j])
                j--;
            else
                i--;
        }
    }

    reverse(longest_common_subsequence_string.begin(), longest_common_subsequence_string.end());
    std::string final_result = X + Y;
    
    // final_result.erase(final_result.find(longest_common_subsequence_string), longest_common_subsequence_length);

    j = 0;
    while (longest_common_subsequence_string[j] != '\0')
    {
        cout << longest_common_subsequence_string[j] << endl;
        final_result.erase(final_result.rfind(longest_common_subsequence_string[j]), 1);
        j++;
    }

    return final_result;
}

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
        string X, Y;
        cin >> X >> Y;
        cout << print_shortest_common_supersequence(X, Y) << endl;
    }
}
// // Sample IO
// 2
// geek eke
// AGGTAB GXTXAYB

// e
// e
// geekk
// G
// T
// A
// B
// AGGTABXXY
