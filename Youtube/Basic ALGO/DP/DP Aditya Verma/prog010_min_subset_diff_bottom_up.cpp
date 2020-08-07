#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

bool minimum_subset_difference(vector<int> elements_array, int array_size)
{
    int elements_array_sum = accumulate(elements_array.begin(), elements_array.end(), 0);

    int **memoization_matrix = new int *[array_size + 1];
    for (int i = 0; i < array_size + 1; i++)
        memoization_matrix[i] = new int[elements_array_sum + 1];

    for (int i = 0; i < array_size + 1; i++)
    {
        for (int j = 0; j < elements_array_sum + 1; j++)
        {
            if (i == 0)
                memoization_matrix[i][j] = false;
            if (j == 0)
                memoization_matrix[i][j] = true;
        }
    }

    for (int i = 1; i < array_size + 1; i++)
    {
        for (int j = 1; j < elements_array_sum + 1; j++)
        {
            if (elements_array[i - 1] <= elements_array_sum)
                memoization_matrix[i][j] = memoization_matrix[i - 1][j - elements_array[i - 1]] ||
                                           memoization_matrix[i - 1][j];
            else
                memoization_matrix[i][j] = memoization_matrix[i - 1][j];
        }
    }

    vector<int> S1_array;
    for (int j = 0; j < (elements_array_sum + 1) / 2; j++)
    {
        // S1_array.push_back(memoization_matrix[array_size][j]);
        if (memoization_matrix[array_size][j] == true)
            S1_array.push_back(j);
    }

    int minimum_value = INT_MAX;
    for (int i = 0; i < S1_array.size(); i++)
    {
        int current_value = elements_array_sum - (2 * S1_array[i]);

        if (current_value < minimum_value)
            minimum_value = current_value;
    }

    for (int i = 0; i < array_size + 1; i++)
        delete[] memoization_matrix[i];
    delete[] memoization_matrix;

    return minimum_value;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput1.txt", "r", stdin);
    freopen("xoutput1.txt", "w", stdout);
#endif

    int array_size, required_sum;
    cin >> array_size;

    vector<int> elements_array;
    for (int i = 0; i < array_size; i++)
        cin >> elements_array[i];

    bool answer = minimum_subset_difference(elements_array, array_size);
    cout << answer;

    return 0;
}
