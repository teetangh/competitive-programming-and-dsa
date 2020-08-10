#include <iostream>
using namespace std;
// #include "solution.h"

// arr - input array
// size - size of array
// x - sum of triplets

void FindTriplet(int arr[], int n, int x)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    if (arr[i] < arr[j] && arr[j] < arr[k])
                        cout << arr[i] << " " << arr[j] << " " << arr[k];
                    else if (arr[i] < arr[k] && arr[k] < arr[j])
                        cout << arr[i] << " " << arr[k] << " " << arr[j];
                    else if (arr[j] < arr[i] && arr[i] < arr[k])
                        cout << arr[j] << " " << arr[i] << " " << arr[k];
                    else if (arr[j] < arr[k] && arr[k] < arr[i])
                        cout << arr[j] << " " << arr[k] << " " << arr[i];
                    else if (arr[k] < arr[i] && arr[i] < arr[j])
                        cout << arr[k] << " " << arr[i] << " " << arr[j];
                    else if (arr[k] < arr[j] && arr[j] < arr[i])
                        cout << arr[k] << " " << arr[j] << " " << arr[i];
                    cout << endl;
                }
            }
        }
    }
}

int main()
{

    int size;

    int x;
    cin >> size;

    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;

    FindTriplet(input, size, x);

    return 0;
}
