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

    int *wt_array = new int[num_of_items];
    int *val_array = new int[num_of_items];

    int curr_item_weight, curr_item_value;
    for (int i = 0; i < num_of_iterations; i++)
    {
        cin >> curr_item_weight >> curr_item_value;
        wt_array[i] = curr_item_weight;
        val_array[i] = curr_item_value;
    }

    int **a = new int *[num_of_items + 1];
    for (int i = 0; i < num_of_items + 1; ++i)
        a[i] = new int[bag_capacity + 1];
    return 0;
}
