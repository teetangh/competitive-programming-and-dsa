#include <iostream>
// #include "solution.h"
using namespace std;

// arr - input array
// n - size of array
void BubbleSort(int arr[], int n)
{
    // Write your code here
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    BubbleSort(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";
}
// Sample Input 1:
// 1
// 7
// 2 13 4 1 3 6 28
// Sample Output 1:
// 1 2 3 4 6 13 28
// Sample Input 2:
// 2
// 5
// 9 3 6 2 0
// 4
// 4 3 2 1
// Sample Output 2:
// 0 2 3 6 9
// 1 2 3 4