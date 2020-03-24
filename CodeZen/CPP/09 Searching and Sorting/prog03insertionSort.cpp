#include <iostream>
// #include "solution.h"
using namespace std;

// arr - input array
// n - size of array
void InsertionSort(int arr[], int n)
{
    // Write your code here
    int temp;
    int i, j;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] < temp)
                break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    InsertionSort(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    return 0;
}
