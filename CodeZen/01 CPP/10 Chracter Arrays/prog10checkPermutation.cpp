#include <iostream>
using namespace std;
// #include "solution.h"

// input1 - first input string
// input2 - second input string
int length(char input[])
{
    int i = 0;
    int count = 0;
    while (input[i] != '\0')
    {
        ++count;
        i++;
    }
    return count;
}

bool isPermutation(char input1[], char input2[])
{
    // Write your code here
    int m = length(input1);
    int n = length(input2);

    int i;
    int j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (input1[i] == input2[j])
            {
                input2[j] = '-1';
                break;
            }
            else if (j == n - 1 && input1[i] != input2[j])
                return false;
        }
    }

    return true;
}

int main()
{
    char input1[1000], input2[1000];
    cin.getline(input1, 1000);
    cin.getline(input2, 1000);
    if (isPermutation(input1, input2) == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
