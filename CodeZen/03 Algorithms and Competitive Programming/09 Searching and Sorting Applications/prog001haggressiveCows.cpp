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

// O(n long d)
bool check(int cows, long long int positions[], int n, long long distance)
{
    int count = 1;
    long long last_position = positions[0];

    for (int i = 1; i < n; i++)
    {
        if (positions[i] - last_position >= distance)
        {
            last_position = positions[i];
            count++;
        }

        if (count == cows)
            return true;
    }
    return false;
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
        int n, c;
        cin >> n >> c;

        long long positions[n];
        for (int i = 0; i < n; i++)
            cin >> positions[i];

        sort(positions, positions + n);
        long long start = 0;
        long long end = positions[n - 1] - positions[0];

        long long ans = -1;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;

            if (check(c, positions, n, mid))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }
}
