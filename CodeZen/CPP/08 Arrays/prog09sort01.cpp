#include <iostream>
#include <algorithm>
// #include "solution.h"
using namespace std;

// arr - input array
// n - size of array

void SortZeroesAndOne(int arr[], int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Update in the given array itself. Don't return or print anything.
     * Taking input and printing output is handled automatically.
     */

    int temp;
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            temp = arr[i];
            arr[i] = arr[ptr];
            arr[ptr] = temp;
            ptr++;
        }
    }
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    SortZeroesAndOne(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";
    return 0;
}
