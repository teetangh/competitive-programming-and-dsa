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

long long merge(ll A[], ll left, ll mid, ll right)
{
    ll i = left, j = mid, k = 0;

    ll temp[right - left + 1];
    long long count = 0;
    while (i < mid && j <= right)
    {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
        {
            temp[k++] = A[j++];
            count += mid - i;
        }
    }

    while (i < mid)
        temp[k++] = A[i++];

    while (j <= right)
        temp[k++] = A[j++];

    for (ll i = left, k = 0; i <= right; i++, k++)
        A[i] = temp[k];

    return count;
}

long long merge_sort(ll A[], ll left, ll right)
{
    long long count = 0;
    if (right > left)
    {
        ll mid = (left + right) / 2;

        long long countLeft = merge_sort(A, left, mid);
        long long countRight = merge_sort(A, mid + 1, right);
        long long myCount = merge(A, left, mid + 1, right);

        return myCount + countLeft + countRight;
    }
    return count;
}

long long getInversions(ll A[], ll n)
{
    long long ans = merge_sort(A, 0, n - 1);
    return ans;
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