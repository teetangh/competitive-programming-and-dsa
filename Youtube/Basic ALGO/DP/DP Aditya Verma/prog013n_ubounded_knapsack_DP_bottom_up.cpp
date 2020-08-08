#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int knapsack_unbounded(vector<int> weight_array, vector<int> value_array, int bag_capacity, int num_of_items)
{
    int **tabulation_matrix = new int *[num_of_items + 1];
    for (int i = 0; i < num_of_items + 1; i++)
        tabulation_matrix[i] = new int[bag_capacity + 1];

    for (int i = 0; i < num_of_items + 1; i++)
        for (int j = 0; j < bag_capacity + 1; j++)
            if (i == 0 || j == 0)
                tabulation_matrix[i][j] = 0;

    for (int i = 1; i < num_of_items + 1; i++)
    {
        for (int j = 1; j < bag_capacity + 1; j++)
        {
            if (weight_array[i - 1] <= j && (j - weight_array[i - 1] >= 0))
                tabulation_matrix[i][j] = max(
                    value_array[i - 1] + tabulation_matrix[i][j - weight_array[i - 1]],
                    tabulation_matrix[i - 1][j]);

            else
                tabulation_matrix[i][j] = tabulation_matrix[i - 1][j];
        }
    }

    int answer = tabulation_matrix[num_of_items][bag_capacity];

    for (int i = 0; i < num_of_items + 1; i++)
        delete[] tabulation_matrix[i];
    delete[] tabulation_matrix;

    return answer;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif

    int num_of_items, bag_capacity;
    cin >> num_of_items >> bag_capacity;

    vector<int> weight_array(num_of_items), value_array(num_of_items);

    int curr_item_weight, curr_item_value;
    for (int i = 0; i < num_of_items; i++)
    {
        cin >> curr_item_weight >> curr_item_value;
        weight_array.push_back(curr_item_weight);
        value_array.push_back(curr_item_value);
    }

    int answer = knapsack_unbounded(weight_array, value_array, bag_capacity, num_of_items);
    cout << answer;

    return 0;
}
