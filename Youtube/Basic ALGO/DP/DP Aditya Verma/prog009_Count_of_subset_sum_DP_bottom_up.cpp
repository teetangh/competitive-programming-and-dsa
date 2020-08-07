#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#include "header002_count_of_subset_sum.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif

    int array_size, required_sum;
    cin >> array_size >> required_sum;

    vector<int> elements_array(array_size);
    for (int i = 0; i < array_size; i++)
        cin >> elements_array[i];

    int answer = count_of_subset_sum(elements_array, array_size, required_sum);
    cout << "Count of Subsets: " << answer;

    return 0;
}
// // Sample IO
// 4 11
// 1
// 5
// 11
// 5

// Count of Subsets: 2