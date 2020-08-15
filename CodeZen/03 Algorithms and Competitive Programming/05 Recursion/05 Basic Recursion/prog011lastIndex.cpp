#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
    if (size == 0)
        return -1;

    if (input[size - 1] == x)
    {
        cout << size << endl;
        return (size - 1);
    }

    int smallerOutput = lastIndex(input, size - 1, x);
    if (smallerOutput != -1)
        return smallerOutput;
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

    cout << lastIndex(input, n, x) << endl;
}
