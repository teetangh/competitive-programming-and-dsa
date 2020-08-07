// wt[]: 1 2 3 4
// val[]:1 2 3 4

// int knapsack (int wt[] , int val[] , int W , int n)
// {
//     Base Condition
//     Choice Diagram
// }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int W, int n)
{
    // Recusion Base Case
    if (n == 0 || W == 0)
        return 0;

    // In case the weight of item is less than the bag's capacity
    // Consider taking the item in the bag or not in order to maximise the profit
    if (wt[n - 1] <= W)
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
                   knapsack(wt, val, W, n - 1));

    // In case the weight of item is more than the bag's capacity
    // Cannot consider the item
    else if (wt[n - 1] > W)
        return knapsack(wt, val, W, n - 1);
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

    int answer = knapsack(weight_array, value_array, bag_capacity, num_of_items);
    cout << answer;

    return 0;
}
