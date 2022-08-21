// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// segment tree
void buildMax(int index, int low, int high, int *arr, int *st)
{
    if (low == high)
    {
        st[index] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildMax(2 * index + 1, low, mid, arr, st);
    buildMax(2 * index + 2, mid + 1, high, arr, st);
    st[index] = max(st[2 * index + 1], st[2 * index + 2]);
}

int queryMax(int index, int low, int high, int l, int r, int *st)
{
    if (low > r || high < l)
        return 0;
    if (low >= l && high <= r)
        return st[index];
    int mid = (low + high) / 2;
    int left = queryMax(2 * index + 1, low, mid, l, r, st);
    int right = queryMax(2 * index + 2, mid + 1, high, l, r, st);
    return max(left, right);
}

void buildMin(int index, int low, int high, int *arr, int *st)
{
    if (low == high)
    {
        st[index] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildMin(2 * index + 1, low, mid, arr, st);
    buildMin(2 * index + 2, mid + 1, high, arr, st);
    st[index] = min(st[2 * index + 1], st[2 * index + 2]);
}

int queryMin(int index, int low, int high, int l, int r, int *st)
{
    if (low > r || high < l)
        return 0;
    if (low >= l && high <= r)
        return st[index];
    int mid = (low + high) / 2;
    int left = queryMin(2 * index + 1, low, mid, l, r, st);
    int right = queryMin(2 * index + 2, mid + 1, high, l, r, st);
    return min(left, right);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int size;
        cin >> size;

        int arr[size];
        for (int i = 0; i < size; i++)
            cin >> arr[i];
        int st[4 * size];
        buildMax(0, 0, size - 1, arr, st);
        buildMin(0, 0, size - 1, arr, st);

        // find max(max(l,r) - min(l,r))
        // for all subarrays of l..r, find max(max(l,r) - min(l,r))
    }

    return 0;
}
