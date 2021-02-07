#include <iostream>
// #include "solution.h"
#include <algorithm>
#include <limits.h>

using namespace std;
// arr - input array
// n - size of array
int minAbsoluteDiff(int arr[], int n)
{

    std::sort(arr, arr + n);

    int min = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] < min)
            min = arr[i] - arr[i - 1];
    }
    return min;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << minAbsoluteDiff(input, size) << endl;

    return 0;
}
