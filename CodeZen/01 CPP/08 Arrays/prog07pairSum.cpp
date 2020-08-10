#include <iostream>
using namespace std;
// #include "solution.h"

void pairSum(int input[], int size, int x)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (input[i] + input[j] == x)
            {
                if (input[i] <= input[j])
                    cout << input[i] << " " << input[j] << endl;
                else if (input[j] < input[i])
                    cout << input[j] << " " << input[i] << endl;
            }
        }
    }
}

int main()
{

    int size;
    int x;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;
    pairSum(input, size, x);

    return 0;
}
