#include <iostream>
using namespace std;
#include <climits>

int main()
{

    // Write your code here
    int arr[10000];
    int n;
    cin >> n;

    int big1 = INT_MIN;
    int big2 = INT_MIN;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > big1)
        {
            big1 = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > big2 && arr[i] < big1)
        {
            big2 = arr[i];
        }
    }

    cout << big2;
}
