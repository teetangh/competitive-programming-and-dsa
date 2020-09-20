#include <iostream>
#include <algorithm>
// #include "solution.h"
using namespace std;

int FindUnique(int *arr, int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int flagIndex;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                continue;
            if (arr[i] == arr[j])
                break;
            else if (j == size - 1)
                flagIndex = i;
        }
    }
    return arr[flagIndex];
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << FindUnique(input, size) << endl;

    return 0;
}
// Sample Input 1:
// 1
// 7
// 2 3 1 6 3 6 2
// Sample Output 1:
// 1
// Sample Input 2:
// 2
// 5
// 2 4 7 2 7
// 9
// 1 3 1 3 6 6 7 10 7
// Sample Output 2:
// 4
// 10