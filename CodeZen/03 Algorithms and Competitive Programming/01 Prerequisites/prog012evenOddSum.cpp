#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int even_sum = 0;
    int odd_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] % 2) == 0 && (i % 2) == 0)
            even_sum += arr[i];
        else if ((arr[i] % 2) != 0 && (i % 2) != 0)
            odd_sum += arr[i];
    }

    cout << even_sum << " " << odd_sum;

    delete[] arr;

    return 0;
}
// Sample Input:
// 5
// 2 3 5 1 4
// Sample Output:
// 6 4