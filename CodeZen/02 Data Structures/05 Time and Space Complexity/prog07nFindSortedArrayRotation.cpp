#include <iostream>
using namespace std;

// #include "solution.h"
// arr - input array
// n - size of array

int arrayRotateCheck(int arr[], int n)
{
    if (n == 0 || n == 1)
        return 0;

    int count = 0;
    int i = 0;
    while (arr[i] < arr[i + 1] && i <= n)
    {
        count++;
        i++;
    }

    if (i == n - 1)
        return 0;
    else
        return count + 1;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << arrayRotateCheck(input, size) << endl;
        delete[] input;
    }

    return 0;
}