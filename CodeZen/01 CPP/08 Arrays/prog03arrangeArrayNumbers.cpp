#include <iostream>
// #include "Solution.h"
using namespace std;

void arrange(int arr[], int n)
{

    /* Don't write main().
     Don't read input, it is passed as function argument.
     Arrange elements in the array "arr" given as input.
     Taking input and printing output is handled automatically.
  */
    int count = 1;
    int i, j;
    if (n % 2 == 0)
    {
        for (i = 0, j = n - i - 1; (i < n / 2 || j >= n / 2);)
        {
            if (count % 2 != 0)
                arr[i++] = count++;
            else
                arr[j--] = count++;
        }
    }

    if (n % 2 != 0)
    {
        for (i = 0, j = n - i - 1; (i <= n / 2 || j > n / 2);)
        {
            if (count % 2 != 0)
                arr[i++] = count++;
            else
                arr[j--] = count++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    arrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete arr;
}
// Sample Input 1 :
// 1
// 6
// Sample Output 1 :
// 1 3 5 6 4 2
// Sample Input 2 :
// 2
// 9
// 3
// Sample Output 2 :
// 1 3 5 7 9 8 6 4 2
// 1 3 2