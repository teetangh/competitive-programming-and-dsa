#include <iostream>
// #include "Solution.h"
using namespace std;

void swapAlternate(int arr[], int size)
{

    /* Don't write main().
     Don't read input, it is passed as function argument.
     Taking input and printing output is handled automatically.
  */
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    swapAlternate(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete arr;
}
