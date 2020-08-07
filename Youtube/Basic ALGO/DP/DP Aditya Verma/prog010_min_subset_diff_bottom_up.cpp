#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;
// void print_MOM(int **memoization_matrix, int array_size, int required_sum)
// {
//     cout << "Current Memoization Matrix Status" << endl;
//     for (int i = 0; i < array_size + 1; i++)
//     {
//         for (int j = 0; j < required_sum + 1; j++)
//             cout << setw(2) << memoization_matrix[i][j];
//         cout << endl;
//     }
//     cout << endl;
// }

int minimum_subset_difference(vector<int> elements_array, int array_size)
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
                memoization_matrix[i][j] = memoization_matrix[i - 1][j - elements_array[i - 1]] || memoization_matrix[i - 1][j];
            else
                memoization_matrix[i][j] = memoization_matrix[i - 1][j];
        }
    }

    // print_MOM(memoization_matrix, array_size, elements_array_sum);

    vector<int> S1_array;
    for (int j = 0; j < (elements_array_sum) / 2; j++)
    {
        // S1_array.push_back(memoization_matrix[array_size][j]);
        if (memoization_matrix[array_size][j] == true)
            S1_array.push_back(j);
    }

    // for (auto &ele : S1_array)
    //     cout << ele << " ";
    // cout << endl;

    int minimum_value = INT_MAX;
    for (int i = 0; i < S1_array.size(); i++)
    {
        minimum_value = min(minimum_value, elements_array_sum - (2 * S1_array[i]));
        cout << minimum_value << endl;
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

    vector<int> elements_array(array_size);
    for (int i = 0; i < array_size; i++)
        cin >> elements_array[i];

    int answer = minimum_subset_difference(elements_array, array_size);
    cout << answer;

    return 0;
}
