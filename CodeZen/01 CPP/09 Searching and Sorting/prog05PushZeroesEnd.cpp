#include <iostream>
// #include "solution.h"
using namespace std;

// arr - input array
// n - size of array

void PushZeroesEnd(int arr[], int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to return or print the output.
     * Taking input and printing output is handled automatically.
     */

    int i = 0;
    int k = 0;
    int temp;
    while (i < n)
    {
        ++i;
        if (arr[k] != 0)
            ++k;
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    PushZeroesEnd(input, size);
    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    return 0;
}
