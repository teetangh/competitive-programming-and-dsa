#include <iostream>
// #include "solution.h"
using namespace std;

// Merge helper function
// Merging two sorted arrays
void merge(int input[], int lb, int ub, int size)
{
    int i = lb;
    int k = 0;
    int mid = (lb + ub) / 2;
    int j = mid + 1;

    int *arr = new int[size];

    while (i <= mid && j <= ub)
    {
        if (input[i] <= input[j])
            arr[k++] = input[i++];
        else
            arr[k++] = input[j++];
    }
    // in case 2nd array is finished but 1st is left
    while (i <= mid)
        arr[k++] = input[i++];
    // in case 1st array is finished but 2nd is left
    while (j <= ub)
        arr[k++] = input[j++];
    // copying the answer back into the original array
    for (k = 0; k < size; k++)
        input[k] = arr[k];
}
void mergeSort(int input[], int size)
{
    int lb = 0;
    int ub = size - 1;
    int mid;
    if (size == 0)
        return;
    else if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeSort(input, mid - lb + 1);
        mergeSort(input + mid + 1, ub - mid);
        merge(input, lb, ub, size);
    }
    else
        return;
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}
