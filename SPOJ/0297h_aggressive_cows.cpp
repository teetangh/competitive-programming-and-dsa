#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

bool check(int cows, long long positions[], int n, long long distance)
{
    // Cow counter
    int count = 1;

    // Maintaining a variable for tracking the last stored positions
    // initialising it with first index
    long long last_position = positions[0];

    for (int i = 1; i < n; i++)
    {
        // If the ith position satisfies the criteria, then place the cow
        if (positions[i] - last_position >= distance)
        {
            last_position = positions[i];
            count++;
        }

        // Once all the cows are place,return true that arrangement is possible
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

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, c;
        cin >> n >> c;

        // Scanning the positions
        long long positions[n];
        for (int i = 0; i < n; i++)
            cin >> positions[i];

        // Sorting the given postions
        sort(positions, positions + n);

        // Start and End range of possible Distances
        long long start = 0;
        long long end = positions[n - 1] - positions[0];

        // Default answer
        long long ans = -1;


        // Binary Search Over all the possible distances in the given interval
        while (start <= end)
        {
            // Calculating the mid while trying to prevent data type overflow
            long long mid = start + (end - start) / 2;

            // Checking the validity of the ditance "mid"
            if (check(c, positions, n, mid))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        // Printing the answer for the current test case
        cout << ans << endl;
    }
}
