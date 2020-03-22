#include <iostream>
// #include "Solution.h"
using namespace std;

int allIndexes(int input[], int size, int x, int output[])
{
    if (size == 0)
        return 0;
    else
    {
        return allIndexes(input, size - 1, x, output);

        if (input[size - 1] == x)
        {
            output[0] = input[size - 1];
        }
    }
}

// int length(char input[ ])
// {
//     int count = 0;
//     for(int i = 0; input [i] != '\0' ; i++ )
//         count++;

//     return count;

// }
// int allIndexes(int input[], int size, int x, int output[]) {

//     static int index = 0 ;
//     static int count = 0 ;

//     if(size == 0 )
//         return -1;
//     if(input[0] == x)
//     {
//         output[++count] = ++index;
//         allIndexes(input + 1, size - 1 , x, output);
//     }
//     else
//         allIndexes(input + 1, size - 1 , x, output);
// }

// int allIndexes(int input[], int size, int x, int output[]) {
//   /* Don't write main().
//      Don't read input, it is passed as function argument.
//      Save all the indexes in the output array passed and return the size of output array.
//      Taking input and printing output is handled automatically.
//   */
//     static int count = 0;
//     if(size == 0 )
//         return - 1;
//     else if (input [ 0 ]  == x)
//     {
//         count++;
//         output[0] = count;
//         return allIndexes(input  + 1 , size -1 , x,output + 1);
//     }
//     else
//     {
//         return allIndexes(input  + 1 , size -1 ,x, output);
//     }
// }

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;

    delete[] output;
}
