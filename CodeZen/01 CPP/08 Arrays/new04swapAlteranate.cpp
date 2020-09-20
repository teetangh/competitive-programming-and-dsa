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
// Sample Input 1:
// 1
// 6
// 9 3 6 12 4 32
// Sample Output 1 :
// 3 9 12 6 32 4
// Sample Input 2:
// 2
// 9
// 9 3 6 12 4 32 5 11 19
// 4
// 1 2 3 4
// Sample Output 2 :
// 3 9 12 6 32 4 11 5 19 
// 2 1 4 3