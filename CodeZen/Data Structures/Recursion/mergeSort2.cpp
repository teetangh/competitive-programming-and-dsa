#include <iostream>
// #include "solution.h"
using namespace std;

void merge(int input[], int lb, int ub, int size)
{
    int i = lb;
    int mid = (lb + ub) / 2;
    int j = mid + 1;

    int *arr = new int[size];

    int k = 0;
    while (i <= mid && j <= ub)
    {
        if (input[i] <= input[j])
            arr[k++] = input[i++];
        else
            arr[k++] = input[i++];
    }
    while (i <= mid)
        arr[k++] = input[i++];
    while (j <= ub)
        arr[k++] = input[j++];

    for (k = 0; k < size; k++)
        input[k] = arr[k];
}

void MergeSort(int *a, int lb, int ub)
{
    int mid;

    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        //Split the data into 2 halves
        MergeSort(a, lb, mid);
        MergeSort(a, mid + 1, ub);
        //Merge them to get Sorted output
        merge(a, lb, ub, ub - lb + 1);
    }
    else
        return;
}

void mergeSort(int input[], int size)
{
    int lb = 0, ub = size - 1;
    MergeSort(input, lb, ub);
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
