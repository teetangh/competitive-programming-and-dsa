//////////////////////////////////////////// INCLUDES ///////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////// FUNCTIONS ///////////////////////////////////////////
void print_MOM(bool **memoization_matrix, int array_size, int required_sum)
{
    cout << "Current Memoization Matrix Status" << endl;
    for (int i = 0; i < array_size + 1; i++)
    {
        for (int j = 0; j < required_sum + 1; j++)
            cout << setw(2) << memoization_matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

bool subset_sum_problem(vector<int> elements_array, int array_size, int required_sum)
{
    bool **memoization_matrix = new bool *[array_size + 1];
    for (int i = 0; i < array_size + 1; i++)
        memoization_matrix[i] = new bool[required_sum + 1];

    for (int i = 0; i < array_size + 1; i++)
    {
        for (int j = 0; j < required_sum + 1; j++)
        {
            if (i == 0)
                memoization_matrix[i][j] = false;
            if (j == 0)
                memoization_matrix[i][j] = true;
        }
    }

    // print_MOM(memoization_matrix, array_size, required_sum);

    for (int i = 1; i < array_size + 1; i++)
    {
        for (int j = 1; j < required_sum + 1; j++)
        {
            // print_MOM(memoization_matrix, array_size, required_sum);
            if (elements_array[i - 1] <= required_sum)
                memoization_matrix[i][j] = (memoization_matrix[i - 1][j - elements_array[i - 1]]) ||
                                           (memoization_matrix[i - 1][j]);
            else
                memoization_matrix[i][j] = (memoization_matrix[i - 1][j]);
        }
    }

    print_MOM(memoization_matrix, array_size, required_sum);
    bool answer = memoization_matrix[array_size][required_sum];

    for (int i = 0; i < array_size + 1; i++)
        delete[] memoization_matrix[i];
    delete[] memoization_matrix;

    return answer;
}