#include <iostream>
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
    for (i = 0, j = n - i - 1; (i <= n / 2 && j <= n / 2 + 1);)
    {
        if (count % 2 != 0)
            arr[i++] = count++;
        else
            arr[j--] = count++;
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
