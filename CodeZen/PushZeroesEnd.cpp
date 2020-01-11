// arr - input array // n - size of array
#include <iostream>
using namespace std;

void PushZeroesEnd(int arr[], int n)
{
    int i = 0;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i];
        }
    }
    while (count < n)
    {
        arr[count++] = arr[i];
    }
}
void PushZeroesEnd2(int arr[], int n)
{
    int temp;
    int i, j;
    for (i = 0; i < n;)
    {
        temp = arr[i];
        if (temp == 0)
        {
            for (j = i + 1; j < n; j++)
            {
                arr[j - 1] = arr[j];
            }
            arr[n - 1] = 0;
        }
        if (arr[i] != 0)
            i++;
        else
        {
            continue;
        }
    }
}

int main()
{

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    PushZeroesEnd(input, size);
    for (int i = 0; i < size; i++)
        cout << input[i] << " ";

    return 0;
}
