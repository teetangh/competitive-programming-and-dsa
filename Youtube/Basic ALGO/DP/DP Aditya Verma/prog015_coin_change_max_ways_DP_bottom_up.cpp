#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int coin_change_dp(vector<int> coin_change_array, int types_of_change, int coin_sum)
{
    int default_value = 0;
    vector<vector<int>> tabulation_matrix;
    tabulation_matrix.resize(types_of_change + 1, vector<int>(coin_sum + 1, default_value));

    for (int i = 1; i < types_of_change + 1; i++)
    {
        for (int j = 1; j < coin_sum + 1; j++)
        {
            if ((coin_change_array[i - 1] <= coin_sum) && (j - coin_change_array[i - 1] >= 0))
                tabulation_matrix[i][j] = coin_change_array[i - 1] + tabulation_matrix[i][j - coin_change_array[i - 1]];
            else
                tabulation_matrix[i][j] = tabulation_matrix[i - 1][j];
        }
    }
    int answer = tabulation_matrix[types_of_change][coin_sum];
    return answer;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int types_of_change, coin_sum;
    cin >> types_of_change >> coin_sum;

    vector<int> coin_change_array(types_of_change);

    int current_coin;
    for (int i = 0; i < types_of_change + 1; i++)
    {
        cin >> current_coin;
        coin_change_array[i] = current_coin;
    }

    int answer = coin_change_dp(coin_change_array, types_of_change, coin_sum);
    cout << answer;

    return 0;
}

// // Sample IO
// 3 4

// 1 2 3

// 4