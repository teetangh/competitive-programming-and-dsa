#include <iostream>
// #include "Solution.h"
using namespace std;

using namespace std;

int lastIndex(int input[], int size, int x)
{
    // for (int i = 0; i < size; i++)
    // {
    //     cout << input[i];
    // }

    cout << endl;

    int answer;
    if (size == 0)
        return -1;

    else
    {
        answer = lastIndex(input + 1, size - 1, x);
        if (input[0] == x)
        {
            if (answer == -1)
                return 0;
            else
                return answer + 1;
        }
        else
        {
            if (answer == -1)
                return -1;
            else
                return answer + 1;
        }
    }
}

// int lastIndex(int input[], int size, int x) {
//     if(size == 0 )
//         return -1;
//     else if (input [ size - 1] == x)
//         return (size -1);
//     else
//         return lastIndex(input , size -1 , x);
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

    cout << lastIndex(input, n, x) << endl;
}
