#include <iostream>
#include <algorithm>
// #include "solution.h"
using namespace std;

// arr - input array
// n - size of array

void SortZeroesAndOne(int arr[], int n)
{
    int temp;
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            temp = arr[i];
            arr[i] = arr[ptr];
            arr[ptr] = temp;
            ptr++;
        }
    }
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    SortZeroesAndOne(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";
    return 0;
}
// Sample Input 1:
// 1
// 7
// 0 1 1 0 1 0 1
// Sample Output 1:
// 0 0 0 1 1 1 1
// Sample Input 2:
// 2
// 8
// 1 0 1 1 0 1 0 1
// 5
// 0 1 0 1 0
// Sample Output 2:
// 0 0 0 1 1 1 1 1
// 0 0 0 1 1