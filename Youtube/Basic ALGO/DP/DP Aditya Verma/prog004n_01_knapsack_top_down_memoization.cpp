
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W, int n, vector<vector<int>> memoization_matrix)
{
    if (n == 0 || W == 0)
        return memoization_matrix[n][W] = 0;

    if (memoization_matrix[n][W] != -1)
        return memoization_matrix[n][W];

    if (wt[n - 1] <= W)
        return memoization_matrix[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1, memoization_matrix),
                                              knapsack(wt, val, W, n - 1, memoization_matrix));

    else if (wt[n - 1] > W)
        return memoization_matrix[n][W] = knapsack(wt, val, W, n - 1, memoization_matrix);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int num_of_items, bag_capacity;
    cin >> num_of_items >> bag_capacity;
    int num_of_iterations = num_of_items;

    vector<int> weight_array, value_array;
    int curr_item_weight, curr_item_value;

    while (num_of_iterations--)
    {
        cin >> curr_item_weight >> curr_item_value;
        weight_array.push_back(curr_item_weight);
        value_array.push_back(curr_item_value);
    }
    ////////////////////////////////2D VECTOR CONSTRUCTOR /////////////////////////////
    // specify default value to fill the vector elements
    int default_value = -1;

    // instantiate vector object of type std::vector<int>
    std::vector<std::vector<int>> memoization_matrix;

    // resize the vector to M elements of type std::vector<int>,
    // each having size N and given default value
    memoization_matrix.resize(num_of_items + 1, std::vector<int>(bag_capacity + 1, default_value));

    for (int index = 0; index < num_of_items; index++)
    {
        memoization_matrix[index][0] = 0;
        memoization_matrix[0][index] = 0;
    }

    /////////////////////////////////////////////////////////////////////////////////

    int answer = knapsack(weight_array, value_array, bag_capacity, num_of_items, memoization_matrix);
    cout << answer;

    return 0;
}
