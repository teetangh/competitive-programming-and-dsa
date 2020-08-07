
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W, int n, vector<vector<int>> matrix)
{
    if (n == 0 || W == 0)
        return 0;

    if (matrix[n][W] != -1)
        return matrix[n][W];

    if (wt[n - 1] <= W)
        return matrix[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1, matrix),
                                  knapsack(wt, val, W, n - 1, matrix));

    else if (wt[n - 1] > W)
        return matrix[n][W] = knapsack(wt, val, W, n - 1, matrix);
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
    std::vector<std::vector<int>> matrix;

    // resize the vector to M elements of type std::vector<int>,
    // each having size N and given default value
    matrix.resize(num_of_items, std::vector<int>(weight_array.size(), default_value));
    /////////////////////////////////////////////////////////////////////////////////

    int answer = knapsack(weight_array, value_array, bag_capacity, num_of_items, matrix);
    cout << answer;

    return 0;
}
