#include <iostream>
// #include "solution.h"
using namespace std;

// arr - input array
// n - size of array

void PushZeroesEnd(int arr[], int n)
{
    int i = 0;
    int k = 0;
    int temp;
    while (i < n)
    {
        ++i;
        if (arr[k] != 0)
            ++k;
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    PushZeroesEnd(input, size);
    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    return 0;
}
// Sample Input 1:
// 1
// 7
// 2 0 0 1 3 0 0
// Sample Output 1:
// 2 1 3 0 0 0 0
//  Explanation for the Sample Input 1 :
// All the zeros have been pushed towards the end of the array/list. Another important fact is that the order of the non-zero elements have been maintained as they appear in the input array/list.
// Sample Input 2:
// 2
// 5
// 0 3 0 2 0
// 4
// 9 0 0 8 2
// Sample Output 2:
// 3 2 0 0 0
// 9 8 2 0 0 