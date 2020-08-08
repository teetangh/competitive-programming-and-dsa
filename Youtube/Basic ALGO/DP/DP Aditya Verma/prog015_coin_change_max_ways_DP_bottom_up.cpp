// The MIT License (MIT)

// Copyright (c) 2020 Kaustav Ghosh

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.
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
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
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