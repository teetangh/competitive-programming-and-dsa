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
            if (elements_array[i - 1] <= required_sum && (j - elements_array[i - 1]) >= 0)
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
