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

void pairStar(char input[])
{
    int n = length(input);

    // cout << " input[0] is " << input[0] << " n is " << n << endl;

    if (input[0] == '\0' || n == 0)
    {
        // cout << "debug 1" << endl;
        return;
    }

    else if (input[0] != input[1])
    {
        // cout << "debug 2" << endl;
        pairStar(input + 1);
    }

    else if (input[0] == input[1])
    {
        // cout << "debug 3" << endl;
        for (int i = n; i >= 1; i--)
            input[i + 1] = input[i];
        input[1] = '*';
        pairStar(input + 2);
    }
    else if (input[0] == input[1] && input[1] == input[2])
    {
        // cout << "debug 4" << endl;
        while (input[0] == input[1])
        {
            for (int i = n; i >= 1; i--)
                input[i] = input[i - 1];
            input[1] = '*';
        }
        pairStar(input + 1);
    }
}

// using namespace std;

// int length(char input[])
// {
//     int count = 0 ;
//     for(int  i = 0; input[i] != '\0' ; i++ )
//         count++;
//     return count;
// }

// void pairStar(char input[])
// {
//     int n = length(input);
//     if(n == 0 )
//         return;

//     else if(input[0] == input[1])
//     {
//         int i;
//         for(i = n ; i>=0 ; i++)
//             input[i] = input[i-1];
//     }
//     else
//         pairStar(input + 1);
// }

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}
