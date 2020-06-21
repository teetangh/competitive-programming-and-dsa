#include <iostream>
using namespace std;
// #include "solution.h"

void printSubset(int input[], int inputSize, int k, int output[], int outputSize)
{
    if (inputSize == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < outputSize; i++)
                cout << output[i] << ' ';
            cout << endl;
        }
        return;
    }

    printSubset(input + 1, inputSize - 1, k, output, outputSize);
    output[outputSize] = input[0];
    printSubset(input + 1, inputSize - 1, k - input[0], output, outputSize + 1);
}
void printSubsetSumToK(int input[], int size, int k)
{
    int output[size];
    printSubset(input, size, k, output, 0);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
