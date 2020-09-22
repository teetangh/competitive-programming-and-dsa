#include <iostream>
// #include "Solution.h"
using namespace std;

int firstIndex(int input[], int size, int x)
{
    if (size == 0)
        return -1;

    if (input[0] == x)
        return 0;

    int smallerOutput = firstIndex(input + 1, size - 1, x);
    if (smallerOutput != -1)
        return 1 + smallerOutput;
    else
        return -1;
}

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
// Sample Input :
// 4
// 9 8 10 8
// 8
// Sample Output :
// 1