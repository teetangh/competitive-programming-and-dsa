#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countArray function below.
long countArray(int n, int k, int x)
{
    auto MOD = 1000000007;

    // dp[2][n] = {0}
    vector<vector<long>> dp;
    dp.resize(2, vector<long>(n, 0));

    dp[0][0] = 1;
    dp[1][0] = 0;

    for (auto j = 1; j < n; j++)
    {
        // One Count
        dp[0][j] = (dp[1][j - 1] * (k - 1)) % MOD;

        // Non-One Count
        dp[1][j] = (dp[0][j - 1] + ((dp[1][j - 1] * (k - 2)) % MOD)) % MOD;
    }

    if (x == 1)
        return dp[0][n - 1] % MOD;
    else
        return dp[1][n - 1] % MOD;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
