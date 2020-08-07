#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int knapsack_bottom_up(int weight_array[], int value_array[], int bag_capacity, int num_of_items)
{

    int **memoization_matrix = new int *[num_of_items + 1];
    for (int i = 0; i < num_of_items + 1; ++i)
        memoization_matrix[i] = new int[bag_capacity + 1];

    // Can't do in O(n) coz matrix not square
    for (int i = 0; i < num_of_items + 1; i++)
    {
        for (int j = 0; j < bag_capacity + 1; j++)
        {
            if (i == 0 || j == 0)
                memoization_matrix[i][j] = 0;
        }
    }

    for (int i = 1; i < num_of_items + 1; i++)
    {
        for (int j = 1; i < bag_capacity + 1; i++)
        {
            if (weight_array[i - 1] <= j)
                memoization_matrix[i][j] = max(value_array[i - 1] + memoization_matrix[i - 1][j - weight_array[i - 1]], memoization_matrix[i - 1][j]);

            else
                memoization_matrix[i][j] = memoization_matrix[i - 1][j];
        }
    }

    int answer = memoization_matrix[num_of_items][bag_capacity];

    for (int i = 0; i < num_of_items + 1; i++)
        delete[] memoization_matrix[i];
    delete[] memoization_matrix;

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

    int answer = knapsack_bottom_up(weight_array, value_array, bag_capacity, num_of_items);
    cout << answer;

    return 0;
}
