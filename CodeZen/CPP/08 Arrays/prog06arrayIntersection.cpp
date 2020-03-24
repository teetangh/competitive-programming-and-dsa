#include <iostream>
#include <algorithm>
using namespace std;
// #include "solution.h"

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array

void intersection(int input1[], int input2[], int size1, int size2)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    for (int i = 0; i < size1; i++)
    {

        for (int j = 0; j < size2; j++)
        {
            if (input1[i] == input2[j])
            {
                input2[j] = -99999;
                cout << input1[i] << endl;
                break;
            }
        }
    }
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

    intersection(input1, input2, size1, size2);

    return 0;
}
