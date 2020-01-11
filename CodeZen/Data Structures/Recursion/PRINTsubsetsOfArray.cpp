#include <iostream>
using namespace std;
// #include "solution.h"
void printArray(int input[], int inputSize, int output[], int outputSize)
{
    // cout << " \n INPUT \n ";
    // for (int i = 0; i < inputSize; i++)
    //     cout << input[i] << " ";
    // cout << "\n OUTPUT \n ";
    if (inputSize == 0)
    {
        for (int i = 0; i < outputSize; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }

    printArray(input + 1, inputSize - 1, output, outputSize);
    output[outputSize] = input[0];
    printArray(input + 1, inputSize - 1, output, outputSize + 1);
}

void printSubsetsOfArray(int input[], int size)
{

    int output[size];
    printArray(input, size, output, 0);
}
int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
