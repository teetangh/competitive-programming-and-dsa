#include <iostream>
using namespace std;
// #include "solution.h"

int longestBitonicSubarray(int *input, int n)
{
    int *lis = new int[n];
    int *lds = new int[n];

    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] >= input[i])
                continue;
            int possibleAns = lis[j] + 1;
            if (possibleAns > lis[i])
                lis[i] = possibleAns;
        }
    }

    lds[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (input[j] >= input[i])
                continue;
            int possibleAns = lds[j] + 1;
            if (possibleAns > lds[i])
                lds[i] = possibleAns;
        }
    }

    int *output = new int[n];
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        output[i] = lis[i] + lds[i] - 1;
        if (output[i] > best)
            best = output[i];
    }

    delete[] lis;
    delete[] lds;
    delete[] output;

    return best;
}

int main()
{
    int n, input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cout << longestBitonicSubarray(input, n);
    return 0;
}
