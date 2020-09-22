#include <iostream>
// #include "solution.h"
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }

    int o1[5000][50];
    int o2[5000][50];

    int temp1 = subsetSumToK(input + 1, n - 1, o1, k - input[0]);
    int temp2 = subsetSumToK(input + 1, n - 1, o2, k);

    // Output 2D array considering the current element
    for (int i = 0; i < temp1; i++)
    {
        o1[i + temp1][0] = o1[i][0] + 1;
        o1[i + temp1][1] = input[0];
        for (int j = 0; j < o1[i][0]; j++)
            o1[i + temp1][j + 2] = o1[i][j + 1];
    }
    // Output 2D array NOT considering the current element
    for (int i = 0; i < temp2; i++)
    {
        o2[i + temp2][0] = o2[i][0];
        // o2[i + temp2][1] = input[0];
        for (int j = 0; j < o2[i][0]; j++)
            o2[i + temp2][j + 1] = o2[i][j + 1];
    }
    // Output 2D array combining the two temporary 2D arrays
    for (int i = temp1; i < 2 * temp1; i++)
        for (int j = 0; j <= o1[i][0]; j++)
            output[i - temp1][j] = o1[i][j];

    for (int i = 0; i < temp2; i++)
        for (int j = 0; j <= o2[i][0]; j++)
            output[i + temp1][j] = o2[i][j];

    return temp1 + temp2;
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
