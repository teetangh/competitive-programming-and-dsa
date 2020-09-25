#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#include "include/header002_count_of_subset_sum.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int array_size, given_difference, required_sum;
    cin >> array_size >> given_difference;

    vector<int> elements_array(array_size);
    for (int i = 0; i < array_size; i++)
        cin >> elements_array[i];

    int elements_array_sum = accumulate(elements_array.begin(), elements_array.end(), 0);
    required_sum = (given_difference + elements_array_sum) / 2;
    int answer = count_of_subset_sum(elements_array, array_size, required_sum);

    cout << "Count of Subsets with the given difference: " << answer;

    return 0;
}