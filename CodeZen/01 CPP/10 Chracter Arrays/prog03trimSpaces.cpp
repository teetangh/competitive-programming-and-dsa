#include <iostream>
using namespace std;
// #include "Solution.h"

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

void trimSpaces(char input[])
{

    int n = length(input);
    // cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == ' ')
        {
            for (int j = i; j < n; j++)
            {
                input[j] = input[j + 1];
            }
        }
        if (input[i] == ' ')
            i--;
    }
}

// void trimSpaces(char []input) {

//     int i,j;
//     for( i = 0 ; input[i] != "\0" ; i ++)
//     {
//         if(input[i] ==  " " )
//         {
//             for(j = i ; input[j] != "\0" ; j ++)
//                 input[j] = input[j+1];
//         }
//     }

// }

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}
// Sample Input :
// abc def g hi
// Sample Output :
// abcdefghi