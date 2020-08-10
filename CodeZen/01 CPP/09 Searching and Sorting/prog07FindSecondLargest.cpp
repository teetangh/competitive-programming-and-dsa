#include <iostream>
using namespace std;
// #include "solution.h"

// arr - input array
// n - size of array

int FindSecondLargest(int arr[], int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int big = -2147483648;
    int big2 = -2147483648;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= big)
            big = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= big2 && arr[i] < big)
            big2 = arr[i];
    }
    return big2;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << FindSecondLargest(input, size);

    return 0;
}