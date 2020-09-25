// Similar to unbounded Knapsack
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rod_cutting_dp(vector<int> piece_length_array, vector<int> price_length_array, int types_of_pieces, int rod_length)
{
    int default_value = 0;
    vector<vector<int>> tabulation_matrix;
    tabulation_matrix.resize(types_of_pieces + 1, vector<int>(rod_length + 1, default_value));

    for (int i = 1; i < types_of_pieces + 1; i++)
    {
        for (int j = 1; j < rod_length + 1; j++)
        {
            if ((piece_length_array[i - 1] <= rod_length) && (j - piece_length_array[i - 1] >= 0))
                tabulation_matrix[i][j] = max(
                    (price_length_array[i - 1] + tabulation_matrix[i][j - piece_length_array[i - 1]]),
                    (tabulation_matrix[i - 1][j]));
            else
                tabulation_matrix[i][j] = tabulation_matrix[i - 1][j];
        }
    }

    int answer = tabulation_matrix[types_of_pieces][rod_length];
    return answer;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int types_of_pieces, rod_length;
    cin >> types_of_pieces >> rod_length;

    vector<int> piece_length_array(types_of_pieces), price_length_array(types_of_pieces);

    int current_piece_length, current_piece_price;
    for (int i = 0; i < types_of_pieces; i++)
    {
        cin >> current_piece_length >> current_piece_price;
        piece_length_array[i] = current_piece_length;
        price_length_array[i] = current_piece_price;
    }

    int answer = rod_cutting_dp(piece_length_array, price_length_array, types_of_pieces, rod_length);
    cout << answer;

    return 0;
}

// // Sampe IO
// 8 8

// 1 3
// 2 5
// 3 8
// 4 9
// 5 10
// 6 17
// 7 17
// 8 20

// 24