#include <iostream>
// #include "solution.h"
using namespace std;

int BinarySearch(int arr[], int n, int val)
{

    int lb = 0;
    int ub = n - 1;

    int mid;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (arr[mid] == val)
            return mid;
        else if (val < arr[mid])
            ub = mid - 1;

        else if (val > arr[mid])
            lb = mid + 1;
    }
    return -1;
}

int main()
{

    int size, val;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cin >> val;
    cout << BinarySearch(input, size, val);
    return 0;
}
// Sample Input 1:
// 7
// 1 3 7 9 11 12 45
// 1
// 3
// Sample Output 1:
// 1
// Sample Input 2:
// 7
// 1 2 3 4 5 6 7
// 2
// 9
// 7
// Sample Output 2:
// -1
// 6