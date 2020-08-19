#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<int> SubtractVectors(vector<int> v1, vector<int> v2)
{
    vector<int> temp_diff_vec;
    for (int i = 0; i < v1.size(); i++)
        temp_diff_vec.push_back(v1[i] - v2[i]);

    return temp_diff_vec;
}

int print_minimum_cost(vector<int> arr, int first_operation, int second_operation)
{
    // Returns 0 if all elements are equal
    if (std::adjacent_find(arr.begin(), arr.end(), std::not_equal_to<>()) == arr.end())
        return 0;

    // Getting min and max elements
    auto max_index = std::max_element(arr.begin(), arr.end());
    auto min_index = std::min_element(arr.begin(), arr.end());
    int max_element = *max_index;
    int min_element = *min_index;

    // Creating the cost array
    int cost_range = max_element - min_element + 1;
    vector<int> cost_array(cost_range);

    int num_of_decreasing = 0;
    int num_of_increasing = 0;
    for (int i = 0; i < cost_range; i++)
    {
        vector<int> target_array(min_element + i);
        vector<int> diff_vector = SubtractVectors(target_array, arr);

        for (auto &ele : diff_vector)
            cout << ele << " ";
        cout << endl;

        for (auto &ele : diff_vector)
        {
            if (ele < 0)
                num_of_decreasing += abs(ele);
            else if (ele > 0)
                num_of_increasing += ele;
            else
                continue;
        }

        if (num_of_increasing >= num_of_decreasing)
            cost_array[i] = INT_MAX;
        else
            cost_array[i] = (first_operation * num_of_decreasing) + (second_operation * (num_of_decreasing - num_of_increasing));

        target_array.clear();
        diff_vector.clear();
    }

    auto min_cost_index = std::min_element(cost_array.begin(), cost_array.end());
    int min_cost_element = *min_cost_index;
    return min_cost_element;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("xinput.txt", "r", stdin);
//     freopen("xoutput.txt", "w", stdout);
// #endif

    int arr_size;
    cin >> arr_size;

    int first_operation, second_operation;
    cin >> first_operation >> second_operation;

    vector<int> arr(arr_size);
    for (int i = 0; i < arr_size; i++)
        cin >> arr[i];

    cout << print_minimum_cost(arr, first_operation, second_operation);

    return 0;
}
