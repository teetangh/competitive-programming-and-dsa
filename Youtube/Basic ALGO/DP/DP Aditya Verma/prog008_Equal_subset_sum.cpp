#include <iostream>
#include <bits/stdc++.h>
#include "header001_subset_sum.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif

    int array_size, required_sum;
    cin >> array_size;

    vector<int> elements_array(array_size);

    for (int i = 0; i < array_size; i++)
        cin >> elements_array[i];

    int elements_array_sum = accumulate(elements_array.begin(), elements_array.end(), 0);
    if (elements_array_sum % 2 != 0)
        cout << false;

    else
    {
        required_sum = elements_array_sum / 2;
        bool answer = subset_sum_problem(elements_array, array_size, required_sum);
        cout << answer;
    }

    return 0;
}
// // Sample IO False
// 4
// 1
// 5
// 11
// 4

// 0

// // Sample IO True
// Current Memoization Matrix Status
//  1 0 0 0 0 0 0 0 0 0 0 0
//  1 1 0 0 0 0 0 0 0 0 0 0
//  1 1 0 0 0 1 1 0 0 0 0 0
//  1 1 0 1 0 1 1 0 0 0 0 1
//  1 1 0 1 0 1 1 0 1 0 1 1

// 1