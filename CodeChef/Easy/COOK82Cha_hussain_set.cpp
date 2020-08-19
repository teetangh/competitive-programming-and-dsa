#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    // Taking the basic input
    int n, m;
    cin >> n >> m;

    // Scanning the array elements
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Sorting the Array
    sort(arr, arr + n);

    queue<ll> q;

    int count_m = 0;   // Counter for the query number
    int end_p = n - 1; // End pointer for the array
    while (m--)
    {
        // Scanning the query number
        int curr_m;
        cin >> curr_m;
        ll ans;

        // using the common counter for all the given chronological queries to iterate upto the current query number
        for (; count_m < curr_m; count_m++)
        {
            if (end_p >= 0 && (q.empty() || arr[end_p] >= q.front()))
            {
                ans = arr[end_p];
                end_p--;
            }
            else
            {
                ans = q.front();
                q.pop();
            }
            q.push(ans / 2);
        }
        cout << ans << endl;
    }

    return 0;
}
