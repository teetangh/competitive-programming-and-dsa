#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int count_of_subset_sum(vector<int> elements_array, int array_size, int required_sum)
{
    int **memoization_matrix = new int *[array_size + 1];
    for (int i = 0; i < array_size + 1; i++)
        memoization_matrix[i] = new int[required_sum + 1];

    for (int i = 0; i < array_size + 1; i++)
    {
        for (int j = 0; j < required_sum + 1; j++)
        {
            if (i == 0)
                memoization_matrix[i][j] = 0;
            if (j == 0)
                memoization_matrix[i][j] = 1;
        }
    }

    for (int i = 1; i < array_size + 1; i++)
    {
        for (int j = 1; j < required_sum + 1; j++)
        {
            if (elements_array[i - 1] <= required_sum)
                memoization_matrix[i][j] = memoization_matrix[i - 1][j - elements_array[i - 1]] +
                                           memoization_matrix[i - 1][j];

            else
                memoization_matrix[i][j] = memoization_matrix[i - 1][j];
        }
    }

    int answer = memoization_matrix[array_size][required_sum];

    for (int i = 0; i < array_size; i++)
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