#include <iostream>
// #include "solution.h"
using namespace std;

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
// input - given string
// You need to update in the given string itself. No need to print or return anything
#include <string.h>
#include <bits/stdc++.h>

void reverseStringWordWise(char input[])
{
    // Write your code here
    int z = strlen(input);
    int j = z - 1;
    for (int i = 0; i < z; i++)
    {
        if (i <= j)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            j--;
        }
    }
    int n;
    int m = 0;
    for (int i = 0; i <= z; i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            n = i;

            int l = n - 1;

            for (int k = m; k < n; k++)
            {
                if (k <= l)
                {
                    int temp = input[k];
                    input[k] = input[l];
                    input[l] = temp;

                    l--;
                }
            }
            m = n + 1;
        }
    }
}
// void reverseStringWordWise(char input[])
// {
//     // Write your code here

//     int n = length(input);
//     int i, j, k;
//     for (i = 0; i < n; i++)
//     {
//         for (j = i; input[j] != ' ' || input[j] != '\0'; j++)
//         {
//         }
//         for (k = i; k <= j; j++)
//         {
//             char temp = input[i];
//             input[i] = input[j - k - 1];
//             input[j - k - 1] = temp;
//         }
//         i = j;
//     }
// }
int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
