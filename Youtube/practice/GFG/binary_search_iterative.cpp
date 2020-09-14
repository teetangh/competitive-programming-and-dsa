#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (x == arr[mid])
            return mid;

        else if (x < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 4, 3, 4, 5, 6, 7, 8, 9, 10};

    int target = 5;

    int n = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, n, target);
}
