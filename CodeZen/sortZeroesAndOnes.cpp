#include <iostream>
using namespace std;

void SortZeroesAndOne(int arr[], int n)
{
    /* Don't write main(). 
    * Don't read input, it is passed as function argument. 
    * Update in the given array itself. Don't return or print anything. 
    * Taking input and printing output is handled automatically. */

    for (int i = 0; i < n; i++)
    {
        while (arr[i] == 1)
        {
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = 1;
        }
    }
}

void SortZeroesAndOne(int arr[], int n)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Update in the given array itself. Don't return or print anything.
     * Taking input and printing output is handled automatically.
     */

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0

        )
        {
            swap arr[i] and arr[ptr] ptr++;
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