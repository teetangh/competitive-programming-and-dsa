#include <iostream>
using namespace std;

int FindUnique(int *arr, int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int flagIndex;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                cout << "Debug 1 i = " << i << " j = " << j << endl;
                continue;
            }
            if (arr[i] == arr[j])
            {
                cout << "Debug 2 i = " << i << " j = " << j << endl;
                // cout << "Debug 2" << endl;
                break;
            }
            else if (j == size - 1)
            {
                cout << "Debug 3 i = " << i << " j = " << j << endl;
                // cout << "Debug 3" << endl;
                flagIndex = i;
            }
        }
    }
    return arr[flagIndex];
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << FindUnique(input, size) << endl;

    return 0;
}
