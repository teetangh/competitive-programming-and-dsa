#include <iostream>
// #include "Solution.h"
using namespace std;

int firstIndex(int input[], int size, int x)
{
    /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
      */
    int answer;
    if (size == 0)
        answer = -1;

    else
    {
        if (input[0] == x)
            return 0;
        else
            answer = firstIndex(input + 1, size - 1, x);
    }

    if (answer == -1)
        return answer;
    else
        return answer + 1;
    // else if(answer == 0 )
    //     return  answer;
    // else
}

// int firstIndex(int input[], int size, int x) {
//   /* Don't write main().
//      Don't read input, it is passed as function argument.
//      Return output and don't print it.
//      Taking input and printing output is handled automatically.
//   */
//     static int Index = 0;

//     if (size  == 0 )
//         return  -1;

//     else
//     {
//         if( input[0] == x)
//                 return Index;
//         else
//         {
//             Index++;
//             return firstIndex(input + 1 , size - 1 , x);
//         }
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

    cout << firstIndex(input, n, x) << endl;
}
