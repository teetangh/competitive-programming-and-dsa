#include <iostream>
// #include "solution.h"
using namespace std;

int subset(int input[], int n, int output[][20])
{
    // Write your code here

    if (sizeof(input) == 0)
    {
        output[0][0] = 0;
        return 0;
    }
    else
    {
        int *smallInteger = (input + 1);
        int smallOutputSize = subset(smallInteger, n / 2, output);
        for (int i = 0; i < smallOutputSize; i++)
            output[i + smallOutputSize] = input[0] + output[i];
    }
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
