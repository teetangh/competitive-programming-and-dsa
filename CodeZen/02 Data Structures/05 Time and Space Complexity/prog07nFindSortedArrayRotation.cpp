#include <iostream>
using namespace std;

// #include "solution.h"
// arr - input array
// n - size of array

// arr - input array
// n - size of array

int arrayRotateCheck(int arr[], int n)
{
    if (n == 0 || n == 1)
        return 0;

    int count = 1;
    int i = 0;
    while (arr[i] <= arr[i + 1] && i < n)
    {
        count++;
        i++;
    }
    return count;
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