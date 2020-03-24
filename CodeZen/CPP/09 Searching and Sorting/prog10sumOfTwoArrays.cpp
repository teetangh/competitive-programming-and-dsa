#include <iostream>
// #include "solution.h"
using namespace std;

// input1 - first array
// size1 - size of first array
// input2 - second array
// size2 - size of second array
// output - array in which sum is to be stored

void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[])
{
    int i = size1;
    int j = size2;
    int carry = 0;
    int tempsum = 0;
    int resultsize;

    if (size1 >= size2)
        resultsize = size1 + 1;
    else if (size1 < size2)
        resultsize = size2 + 1;

    int initialsize = resultsize;

    while (i >= 0 && j >= 0)
    {
        tempsum = carry + input1[i] + input2[j];
        output[resultsize] = tempsum % 10;
        carry = tempsum / 10;
        i--;
        j--;
        resultsize--;
    }
    while (i >= 0)
    {
        output[resultsize--] = (carry) + input1[i--];
        carry = 0;
    }

    while (j >= 0)
    {
        output[resultsize--] = (carry) + input2[j--];
        carry = 0;
    }

    if (carry)
        output[resultsize--] = (carry);
}

int main()
{
    int size1, size2;
    cin >> size1;
    int *input1 = new int[1 + size1];

    for (int i = 0; i < size1; i++)
        cin >> input1[i];

    cin >> size2;
    int *input2 = new int[1 + size2];

    for (int i = 0; i < size2; i++)
        cin >> input2[i];

    int *output = new int[1 + max(size1, size2)];
    int outsize = 1 + max(size1, size2);
    sumOfTwoArrays(input1, size1, input2, size2, output);

    for (int i = 0; i < outsize; i++)
        cout << output[i] << " ";
}
