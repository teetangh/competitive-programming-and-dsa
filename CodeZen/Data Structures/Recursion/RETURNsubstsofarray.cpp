#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20])
{
    if (n == 0)
    {
        output[0][0] = 0;
        // output[0][1] = ' ';
        // output[1][0] = '\0';
        return 1;
    }

    else
    {
        int smallIntegerLength = n - 1;
        int *smallInteger = new int[smallIntegerLength];
        for (int i = 0; input[i] != '\0'; i++)
            smallInteger[i] = input[i];
        smallInteger[smallIntegerLength - 1] = '\0';

        int smallOutputSize = subset(smallInteger, smallIntegerLength, output);

        int i, j, tempCounter;
        for (i = 0; i < smallOutputSize; i++)
        {
            tempCounter = 0;
            for (j = 1; smallInteger[j] != '\0'; j++)
            {
                tempCounter++;
                output[i][j] = smallInteger[j];
            }
            output[i][j] = '\0';
            output[i][0] = tempCounter;
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
