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
// Sample Input 1 :
// 6
// 3 12 34 2 0 -1
// Sample Output 1 :
// 34 2 0 -1
// Sample Input 2 :
// 5
// 13 17 5 4 6
// Sample Output 2 :
// 17 6