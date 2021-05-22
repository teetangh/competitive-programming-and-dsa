#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;
// void print_MOM(int **tabulation_matrix, int array_size, int required_sum)
// {
//     cout << "Current Memoization Matrix Status" << endl;
//     for (int i = 0; i < array_size + 1; i++)
//     {
//         for (int j = 0; j < required_sum + 1; j++)
//             cout << setw(2) << tabulation_matrix[i][j];
//         cout << endl;
//     }
//     cout << endl;
// }

int minimum_subset_difference(vector<int> elements_array, int array_size)
{
    int elements_array_sum = accumulate(elements_array.begin(), elements_array.end(), 0);

    int **tabulation_matrix = new int *[array_size + 1];
    for (int i = 0; i < array_size + 1; i++)
        tabulation_matrix[i] = new int[elements_array_sum + 1];

    for (int i = 0; i < array_size + 1; i++)
    {
        for (int j = 0; j < elements_array_sum + 1; j++)
        {
            if (i == 0)
                tabulation_matrix[i][j] = false;
            if (j == 0)
                tabulation_matrix[i][j] = true;
        }
    }

    for (int i = 1; i < array_size + 1; i++)
    {
        for (int j = 1; j < elements_array_sum + 1; j++)
        {
            // CAUTION
            // CHECK FOR OUT OF BOUND INDEX ERROR IN MEMOIZATION MATRIX
            // USING 2ND CODITION IN IF STATEMENT BELOW
            if (elements_array[i - 1] <= elements_array_sum && j - elements_array[i - 1] >= 0)
                tabulation_matrix[i][j] = tabulation_matrix[i - 1][j - elements_array[i - 1]] || tabulation_matrix[i - 1][j];
            else
                tabulation_matrix[i][j] = tabulation_matrix[i - 1][j];
        }
    }

    // print_MOM(tabulation_matrix, array_size, elements_array_sum);

    vector<int> S1_array;
    for (int j = 0; j <= (elements_array_sum) / 2; j++)
    {
        // S1_array.push_back(tabulation_matrix[array_size][j]);
        if (tabulation_matrix[array_size][j] == true)
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
        delete[] tabulation_matrix[i];
    delete[] tabulation_matrix;

    return minimum_value;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int array_size, required_sum;
    cin >> array_size;

    vector<int> elements_array(array_size);
    for (int i = 0; i < array_size; i++)
        cin >> elements_array[i];

    int answer = minimum_subset_difference(elements_array, array_size);
    cout << endl
         << answer;

    return 0;
}

// Sample IO 1
// 6
// 3 1 4 2 2 1 
// 1

// Sample IO 2
// 4
// 1 5 6 11
// 1