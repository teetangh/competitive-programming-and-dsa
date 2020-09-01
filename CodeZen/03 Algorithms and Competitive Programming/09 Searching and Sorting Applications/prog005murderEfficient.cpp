// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

int stairs_sum_helper(int arr[], int low, int size)
{
    if (size == 0 || size == 1)
        return 0;

    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;

    int sum1 = stairs_sum_helper(arr, low, mid);
    int sum2 = stairs_sum_helper(arr, mid + 1, high);

    sort(arr, arr + mid);
    sort(arr + mid + 1, arr + high);

    int arr2[size];
    int i = 0;
    int j = mid;
    int k = 0;

    int tempcount = 0;
    while (i <= mid && j <= size)
    {
        if (arr[i] <= arr[j])
        {
            tempcount += size - j;
            arr2[k++] = arr[i++];
        }
        else
        {
            arr2[k++] = arr[i++];
        }
    }

    while (i <= mid)
        arr2[k++] = arr[i++];

    while (j <= size)
        arr2[k++] = arr[i++];

    return sum1 + sum2 + tempcount;
}

int stairs_sum(int arr[], int size)
{
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;

    return stairs_sum_helper(arr, low, size);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int size;
        cin >> size;
        int arr[size];

        for (int i = 0; i < size; i++)
            cin >> arr[i];

        cout << stairs_sum(arr, size) << endl;
        // vec.clear();
    }
}
