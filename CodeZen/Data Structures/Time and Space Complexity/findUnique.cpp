#include <iostream>
#include <algorithm>
// #include "solution.h"
using namespace std;
// arr - input array
// size - size of array

int FindUnique(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool unique = true;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                unique = false;
                break;
            }
        }
        if (unique == true)
            return arr[i];
    }
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
