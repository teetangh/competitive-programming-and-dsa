#include <iostream>
using namespace std;
// #include "solution.h"

// arr - input array
// n - size of array

int FindSecondLargest(int arr[], int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int big = -2147483648;
    int big2 = -2147483648;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= big)
            big = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= big2 && arr[i] < big)
            big2 = arr[i];
    }
    return big2;
}

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << FindSecondLargest(input, size);

    return 0;
}
// Sample Input 1:
// 1
// 7
// 2 13 4 1 3 6 28
// Sample Output 1:
// 13
// Sample Input 2:
// 1
// 5
// 9 3 6 2 9
// Sample Output 2:
// 6
// Sample Input 3:
// 2
// 2
// 6 6
// 4
// 90 8 90 5
// Sample Output 3:
// -2147483648
// 8