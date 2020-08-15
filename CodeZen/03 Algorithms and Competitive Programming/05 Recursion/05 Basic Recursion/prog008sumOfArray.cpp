#include <iostream>
// #include "Solution.h"
using namespace std;

int sum(int input[], int n)
{

    if (n == 0)
        return 0;
    if (n == 1)
        return input[0];

    int smallerOutput = sum(input + 1, n - 1);

    return input[0] + smallerOutput;
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

    cout << sum(input, n) << endl;
}
// Sample Input 1 :
// 3
// 9 8 9
// Sample Output 1 :
// 26
// Sample Input 2 :
// 3
// 4 2 1
// Sample Output 2 :
// 7