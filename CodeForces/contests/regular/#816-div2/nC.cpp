// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

// Awesomeness of [1,7,7,7,9,9,9,] is 3 because it can be split into [1],[7,7,7] and [9,9,9].
// Segmen Tree
void build(vector<lli> &seg, vector<lli> &arr, int node, int start, int end)
{
    if (start == end)
    {
        seg[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(seg, arr, node * 2, start, mid);
    build(seg, arr, node * 2 + 1, mid + 1, end);
    if (arr[node * 2] == arr[node * 2 + 1])
        seg[node] = arr[node * 2] + arr[node * 2 + 1] - 1;
    else
        seg[node] = arr[node * 2] + arr[node * 2 + 1];
}

void update(vector<lli> &seg, int node, int start, int end, int idx, lli val)
{
    if (start == end)
    {
        seg[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(seg, node * 2, start, mid, idx, val);
    else
        update(seg, node * 2 + 1, mid + 1, end, idx, val);
    if (seg[node * 2] == seg[node * 2 + 1])
        seg[node] = seg[node * 2] + seg[node * 2 + 1] - 1;
    else
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

lli total(vector<lli> &seg)
{
    // calculate sum of awesomeness for all subarrays from [start,end]
    lli sum = 0;
    for (int i = 0; i < seg.size(); i++)
        sum += seg[i];
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    ulli n, q;
    cin >> n >> q;
    vector<lli> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<lli> seg(4 * n);
    build(seg, arr, 1, 0, n - 1);

    while (q--)
    {
        ulli idx, val;
        cin >> idx >> val;
        update(seg, 1, 0, n - 1, idx - 1, val);
        cout << total(seg) << endl;
    }

    return 0;
}
