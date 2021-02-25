#include <iostream>
// #include "solution.h"
using namespace std;

int subset(int input[], int n, int output[][20])
{
    if (n <= 0)
    {
        output[0][0] = 0; //if n=0 then there is no element so just make size=0 and return 1 that there is an empty subset
        return 1;
    }

    else
    {

        int smallOutputSize = subset(input + 1, n - 1, output); //recursion call
        int i, j;
        for (i = 0; i < smallOutputSize; i++)
        {
            output[i + smallOutputSize][0] = output[i][0] + 1; //since we need to copy the elements and insert input[0]
            output[i + smallOutputSize][1] = input[0];         //at the beginning therefore size is first increased by 1 then
            //input[0] is stored as first element
            //tempCounter = 0;
            for (j = 0; j < output[i + smallOutputSize][0]; j++)
            {
                output[i + smallOutputSize][j + 2] = output[i][j + 1];
            }
        }

        return 2 * smallOutputSize;
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
