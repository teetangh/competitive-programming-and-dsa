#include <iostream>
#include <climits>
using namespace std;

void Leaders(int *arr, int len)
{
    int i, j;
    bool leader = true;
    for (i = 0; i < len; i++)
    {
        leader = true;
        for (j = i + 1; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }
        if (leader)
            cout << arr[i] << ' ';
    }
}

int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}
