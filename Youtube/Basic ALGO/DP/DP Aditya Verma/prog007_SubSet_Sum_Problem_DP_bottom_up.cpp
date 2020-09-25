#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include "include/header001_subset_sum.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int array_size, required_sum;
    cin >> array_size >> required_sum;

    vector<int> elements_array(array_size);

    for (int i = 0; i < array_size; i++)
        cin >> elements_array[i];

    bool answer = subset_sum_problem(elements_array, array_size, required_sum);
    cout << answer;

    return 0;
}
// // Sample IO
// 4 6
// 2
// 1
// 4
// 3

// Current Memoization Matrix Status
//  1 0 0 0 0 0 0
//  1 0 1 0 0 0 0
//  1 1 1 1 0 0 0
//  1 1 1 1 1 1 1
//  1 1 1 1 1 1 1

// 1