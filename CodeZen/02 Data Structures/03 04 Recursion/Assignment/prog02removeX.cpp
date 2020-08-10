#include <iostream>
// #include "solution.h"
using namespace std;

using namespace std;

int length(char input[])
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
        count++;
    return count;
}

void removeX(char input[])
{
    int n = length(input);

    if (input[0] == '\0')
        return;

    if (input[0] != 'x')
        removeX(input + 1);

    else if (input[0] == 'x' && input[1] != 'x')
    {
        for (int i = 0; i < n; i++)
            input[i] = input[i + 1];

        removeX(input + 1);
    }
    else if (input[0] == 'x' && input[1] == 'x')
    {
        while (input[0] == 'x')
        {
            for (int i = 0; i < n; i++)
                input[i] = input[i + 1];
        }
        removeX(input + 1);
    }
}

// Change in the given string itself. So no need to return or print anything
// int length(char input[])
// {
//     int count = 0 ;
//     for(int i = 0 ; input[i] != '\0' ; i++ )
//         count++;
//     return count;
// }
// void removeX(char input[]) {
//     // Write your code here
//     int n =length(input);

//     if(n == 0 )
//         return;
//     else if(input[0] = 'x')
//     {
//         while(input[0] = 'x' && input[1] != '\0')
//             for( int i = 0 ; input[i] !='\0'  ; i++)
//                 input[i] = input[i + 1 ];
//     }
//     return removeX(input + 1);

// }

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
