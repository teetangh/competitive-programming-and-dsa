#include <iostream>
// #include "solution.h"
using namespace std;

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
            arr[k++] = input[i++];
    }
    while (i <= mid)
        arr[k++] = input[i++];
    while (j <= ub)
        arr[k++] = input[j++];

    for (k = 0; k < size; k++)
        input[k] = arr[k];
}
void mergeSort(int input[], int size)
{
    // Write your code here
    int lb = 0;
    int ub = size - 1;
    int mid;
    if (size == 0)
    {
        cout << "debug 1" << endl;
        return;
    }
    else if (lb < ub)
    {
        cout << "debug 2" << endl;
        mid = (lb + ub) / 2;
        mergeSort(input, mid - lb + 1);
        mergeSort(input + mid + 1, ub - mid);
        merge(input, lb, ub, size);
    }
    else
    {
        cout << "debug 3" << endl;
        return;
    }
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
