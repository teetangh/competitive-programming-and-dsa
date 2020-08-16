#include <iostream>
using namespace std;
// #include "solution.h"

// arr - input array
// size - size of array

int DuplicateNumber(int arr[], int size)
{

    int actualSum = ((size - 1) * (size - 2)) / 2;
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum - actualSum;
}
int main()
{
    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << DuplicateNumber(input, size);

    delete[] input;

    return 0;
}