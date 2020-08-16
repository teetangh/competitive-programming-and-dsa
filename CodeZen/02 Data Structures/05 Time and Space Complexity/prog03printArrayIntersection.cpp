#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

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
    while (i <= mid)
        arr[k++] = input[i++];
    while (j <= ub)
        arr[k++] = input[j++];

    for (k = 0; k < size; k++)
        input[k] = arr[k];
}
void mergeSort(int input[], int size)
{
    int lb = 0;
    int ub = size - 1;
    int mid;
    if (size == 0)
    {
        return;
    }
    else if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergeSort(input, mid - lb + 1);
        mergeSort(input + mid + 1, ub - mid);
        merge(input, lb, ub, size);
    }
    else
    {
        return;
    }
}

void intersection(int input1[], int input2[], int size1, int size2)
{
    mergeSort(input1, size1);
    mergeSort(input2, size2);

    int i = 0,
        j = 0;

    while (i <= size1 && j <= size2)
    {
        if (input1[i] == input2[j])
        {
            cout << input1[i] << endl;
            i++;
            j++;
            // break;
        }
        else if (input1[i] < input2[j])
            i++;
        else
            j++;
    }
}

int main()
{

    int size1, size2;

    cin >> size1;
    int *input1 = new int[1 + size1];

    for (int i = 0; i < size1; i++)
        cin >> input1[i];

    cin >> size2;
    int *input2 = new int[1 + size2];

    for (int i = 0; i < size2; i++)
        cin >> input2[i];

    intersection(input1, input2, size1, size2);

    return 0;
}
