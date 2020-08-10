#include <iostream>
// #include "solution.h"
using namespace std;

// arr - input array
// size - size of array

int MissingNumber(int arr[], int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int flagIndex;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                flagIndex = i;
        }
    }
    return arr[flagIndex];
}

int main()
{
    // your code goes here
    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << MissingNumber(input, size);

    return 0;
}
