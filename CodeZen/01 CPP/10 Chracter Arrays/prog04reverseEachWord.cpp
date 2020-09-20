#include <iostream>
// #include "solution.h"
using namespace std;

// input - given string
// You need to update in the given string itself. No need to print or return anything

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
void reverseEachWord(char input[])
{
    // Write your code here
    int n = length(input);
    int i, j, k;
    char temp;
    for (i = 0; input[i] != '\0';)
    {
        for (j = i; input[j] != '\0'; j++)
        {
            // std::cout << "@ i " << i << " j " << j << " k " << k << " \n ";
            if (input[j] == ' ')
                break;
        }
        for (k = i; k < ((j + i) / 2); k++)
        {
            // std::cout << "$ i " << i << " j " << j << " k " << k << " \n ";
            temp = input[k];
            input[k] = input[i + j - k - 1];
            input[i + j - k - 1] = temp;
        }
        i = j + 1;
    }
}
void reverseStringWordWise(char input[])
{
    int n = length(input);

    for (int i = 0; i < n / 2; i++)
    {
        char newtemp = input[i];
        input[i] = input[n - i - 1];
        input[n - i - 1] = newtemp;
    }

    reverseEachWord(input);
}
// void reverseStringWordWise(char input[]) {
//     int n = length(input);
//     int i , j , k;
//     for( i = 0 ; i < n ; i ++)
//     {
//         for( j = 0 ; input[j] != ' ' || input[j] != '\0' ; j++)
//         {}
//         for( k = i ; k <=j ; j++)
//         {
//             char temp = input[i];
//             input[i] = input[j];
//             input[j] = temp;
//         }
//         i=j;
//     }
// }

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
// Sample Input 1:
// Welcome to Coding Ninjas
// Sample Output 1:
// Ninjas Coding to Welcome
// Sample Input 2:
// Always indent your code
// Sample Output 2:
// code your indent Always