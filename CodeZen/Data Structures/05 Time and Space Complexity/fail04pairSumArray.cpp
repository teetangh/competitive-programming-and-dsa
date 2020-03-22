#include <iostream>
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

void pairSum(int input[], int size, int x)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    mergeSort(input, size);
    int i = 0;
    int j = size - 1;

    int Jcounter = 0;

    while (i < j)
    {
        // cout << " i= " << i << " j= " << j << " JCounter= " << Jcounter << endl;
        if (input[i] + input[j] < x)
            i++;
        else if (input[i] + input[j] > x)
            j--;

        else if (input[i] + input[j] == x)
        {
            Jcounter++;
            cout << input[i] << " " << input[j] << endl;
            if (input[i] + input[j - 1] != x)
            {
                j = j + Jcounter;
                i++;
                Jcounter = 0;
            }
            j--;
        }
    }
}

int main()
{

    int size;
    int x;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;
    pairSum(input, size, x);

    return 0;
}
