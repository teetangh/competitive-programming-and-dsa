#include <iostream>
// #include "solution.h"
using namespace std;
// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.
void stringCompression(char input[])
{

    int count = 1;
    char current = input[0];
    int nextindex = 1;
    for (int i = 1; input[i] != '\0'; i++)
    {
        if (input[i] == current)
            count++;
        else
        {
            if (count > 1)
            {
                input[nextindex] = count + '0';
                nextindex++;
            }
            current = input[i];
            input[nextindex] = input[i];
            nextindex++;
            count = 1;
        }
    }
    if (count > 1)
    {
        input[nextindex] = count + '0';
        nextindex++;
    }
    input[nextindex] = '\0';
}
// void stringCompression(char input[])
// {
//     int i, j, k;
//     int count = 0;
//     for (i = 0; input[i] != '\0';)
//     {
//         if (input[i] != input[i + 1])
//         {
//             i++;
//         }
//         else
//             while (input[i] == input[i + 1])
//             {
//                 for (j = i; input[j] == input[i] && input[j] != '\0'; j++)
//                 {
//                     ++count;
//                     input[j] = input[j + 1];
//                 }
//                 // cout << count << " ";
//                 input[i + 1] = count;
//                 count = 0;
//                 i = i + 2;
//             }
//     }
// }

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}
// Sample Input 1 :
// aaabbccdsa
// Sample Output 1 :
// a3b2c2dsa
// Sample Input 2 :
// aaabbcddeeeee
// Sample Output 2 :
// a3b2cd2e5