#include <iostream>
// #include "solution.h"
#include <algorithm>
using namespace std;

long long getInversions(long long *arr, int n)
{
    if (n <= 1)
        return 0;

    if (n == 2)
        return arr[0] > arr[1];

    long long inversions1 = getInversions(arr, n / 2);
    long long inversions2 = getInversions(arr + n / 2, n / 2);

    long long count1 = 0;
    for (int i = 0; i < n / 2 - 1; i++)
    {
        for (int j = i + 1; j < n / 2; j++)
        {
            if (arr[i] > arr[j])
                count1++;
        }
    }

    long long count2 = 0;
    for (int i = n / 2; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count2++;
        }
    }
    // long long count1 = 0;
    // long long count2 = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] > arr[j] && i < (n / 2 - 1) && j < n / 2)
    //             count1++;
    //         if (arr[i] > arr[j] && i >= (n / 2 - 1) && j < n)
    //             count2++;
    //     }
    // }

    sort(arr, arr + n / 2);
    sort(arr + n / 2, arr + n);

    long long *final_arr = new long long[n];
    long long i = 0;
    long long j = n / 2;

    long long count3 = count1 + count2 + inversions1 + inversions2;
    long long k = 0;
    while (i < n / 2 && j < n)
    {
        if (arr[i] <= arr[j])
        {
            final_arr[k++] = arr[i++];
        }
        else if (arr[i] > arr[j])
        {
            count3 += n / 2 - i;
            final_arr[k++] = arr[j++];
        }
    }

    while (i < n / 2)
        final_arr[k++] = arr[i++];

    while (j < n)
        final_arr[k++] = arr[j++];

    for (int i = 0; i < n; i++)
        arr[i] = final_arr[i];
    delete[] final_arr;

    // for (int i = 0, k = 0; i < n; i++, k++)
    //     arr[i] = final_arr[k];

    return count3;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    long long *arr = new long long[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}
