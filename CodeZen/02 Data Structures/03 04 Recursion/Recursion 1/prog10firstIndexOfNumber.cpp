#include <iostream>
// #include "Solution.h"
using namespace std;

int firstIndex(int input[], int size, int x)
{
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
