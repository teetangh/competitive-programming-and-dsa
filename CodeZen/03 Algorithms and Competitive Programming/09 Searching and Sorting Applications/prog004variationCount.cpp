// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

long variationPairs(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = 0, j = 1;

    long count = 0;
    while (j < n)
    {
        if ((arr[j] - arr[i]) >= k)
        {
            count += (n - j);
            i++;
        }
        else
            j++;
    }
    return count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long count = variationPairs(arr, n, k);
    cout << count << endl;
    return 0;
}
// // Sample IO
// 3 1 
// 3 1 3

// 2
