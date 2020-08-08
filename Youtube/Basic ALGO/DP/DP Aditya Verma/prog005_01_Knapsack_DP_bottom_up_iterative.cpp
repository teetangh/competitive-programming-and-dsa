#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

void print_MOM(vector<vector<int>> tabulation_matrix, int array_size, int required_sum)
{
    cout << "Current Tabulation Matrix Status" << endl;
    for (int i = 0; i < array_size + 1; i++)
    {
        for (int j = 0; j < required_sum + 1; j++)
            cout << setw(3) << tabulation_matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

int knapsack_bottom_up(vector<int> weight_array, vector<int> value_array, int bag_capacity, int num_of_items)
{
    int default_value = 0;
    vector<vector<int>> tabulation_matrix;
    tabulation_matrix.resize(num_of_items + 1, vector<int>(bag_capacity + 1, default_value));

    // for (auto &ele : weight_array)
    //     cout << setw(3) << ele;
    // cout << endl;

    // for (auto &ele : value_array)
    //     cout << setw(3) << ele;
    // cout << endl;

    for (int i = 1; i < num_of_items + 1; i++)
    {
        for (int j = 1; j < bag_capacity + 1; j++)
        {
            if ((weight_array[i - 1] <= bag_capacity) && (j - weight_array[i - 1] >= 0))
                tabulation_matrix[i][j] = max((value_array[i - 1] + tabulation_matrix[i - 1][j - weight_array[i - 1]]), tabulation_matrix[i - 1][j]);
            else
                tabulation_matrix[i][j] = tabulation_matrix[i - 1][j];
        }
    }

    print_MOM(tabulation_matrix, num_of_items, bag_capacity);

    int answer = tabulation_matrix[num_of_items][bag_capacity];

    return answer;
}

// int knapsack_bottom_up(int weight_array[], int value_array[], int bag_capacity, int num_of_items)
// {

//     int **tabulation_matrix = new int *[num_of_items + 1];
//     for (int i = 0; i < num_of_items + 1; ++i)
//         tabulation_matrix[i] = new int[bag_capacity + 1];

//     // Can't do in O(n) coz matrix not square
//     for (int i = 0; i < num_of_items + 1; i++)
//     {
//         for (int j = 0; j < bag_capacity + 1; j++)
//         {
//             if (i == 0 || j == 0)
//                 tabulation_matrix[i][j] = 0;
//         }
//     }

//     for (int i = 1; i < num_of_items + 1; i++)
//     {
//         for (int j = 1; i < bag_capacity + 1; i++)
//         {
//             if (weight_array[i - 1] <= j && (j - weight_array[i - 1]) >= 0)
//                 tabulation_matrix[i][j] = max(value_array[i - 1] + tabulation_matrix[i - 1][j - weight_array[i - 1]], tabulation_matrix[i - 1][j]);

//             else
//                 tabulation_matrix[i][j] = tabulation_matrix[i - 1][j];
//         }
//     }

//     int answer = tabulation_matrix[num_of_items][bag_capacity];

//     for (int i = 0; i < num_of_items + 1; i++)
//         delete[] tabulation_matrix[i];
//     delete[] tabulation_matrix;

//     return answer;
// }

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif

    int num_of_items, bag_capacity;
    cin >> num_of_items >> bag_capacity;
    int num_of_iterations = num_of_items;

    // int *weight_array = new int[num_of_items];
    // int *value_array = new int[num_of_items];

    // int curr_item_weight, curr_item_value;
    // for (int i = 0; i < num_of_iterations; i++)
    // {
    //     cin >> curr_item_weight >> curr_item_value;
    //     weight_array[i] = curr_item_weight;
    //     value_array[i] = curr_item_value;
    // }

    vector<int> weight_array(num_of_items), value_array(num_of_items);
    int curr_item_weight, curr_item_value;
    for (int i = 0; i < num_of_iterations; i++)
    {
        cin >> curr_item_weight >> curr_item_value;
        weight_array[i] = curr_item_weight;
        value_array[i] = curr_item_value;
    }

    int answer = knapsack_bottom_up(weight_array, value_array, bag_capacity, num_of_items);
    cout << answer;

    return 0;
}
