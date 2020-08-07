#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int num_of_items, bag_capacity;
    cin >> num_of_items >> bag_capacity;
    int num_of_iterations = num_of_items;

    int *weight_array = new int[num_of_items];
    int *value_array = new int[num_of_items];

    int curr_item_weight, curr_item_value;
    for (int i = 0; i < num_of_iterations; i++)
    {
        cin >> curr_item_weight >> curr_item_value;
        weight_array[i] = curr_item_weight;
        value_array[i] = curr_item_value;
    }

    int **memoization_matrix = new int *[num_of_items + 1];
    for (int i = 0; i < num_of_items + 1; ++i)
        memoization_matrix[i] = new int[bag_capacity + 1];

    for (int i = 0; i < num_of_items + 1; i++)
    {
        for (int j = 0; j < bag_capacity + 1; j++)
        {
            if (i == 0 || j == 0)
                memoization_matrix[i][j] = 0;
        }
    }

    int answer = knapsack(weight_array, value_array, bag_capacity, num_of_items, memoization_matrix);
    cout << answer;

    for (int i = 0; i < num_of_items + 1; i++)
        delete[] memoization_matrix[i];
    delete[] memoization_matrix;

    return 0;
}
