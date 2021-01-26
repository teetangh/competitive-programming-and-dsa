#include <iostream>
#include <iomanip>
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int cost = 0;
    int i;
    for (i = 0; a[i + 1] != '\0'; i++)
    {
        // cout << 'i' << i << endl;
        if (a[i] == b[i])
            continue;

        // Swap if adjacent invalid
        else if (a[i] != b[i] && a[i] != a[i + 1] && a[i + 1] != b[i + 1])
        {
            swap(a[i], a[i + 1]);
            // i++;
        }

        else if (a[i] != b[i])
        {
            a[i] ^= 1;
        }
        cost++;
    }

    if (a[i] != b[i])
    {
        a[i] ^= 1;
        cost++;
    }

    cout << cost << endl;
    return 0;
}
// Test: #1, time: 15 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
// Input
// 3
// 100
// 001
// Output
// 2
// Answer
// 2

// Test: #2, time: 0 ms., memory: 4 KB, exit code: 0, checker exit code: 0, verdict: OK
// Input
// 4
// 0101
// 0011
// Output
// 1
// Answer
// 1

// Test: #3, time: 0 ms., memory: 12 KB, exit code: 0, checker exit code: 0, verdict: OK
// Input
// 8
// 10001001
// 01101110
// Output
// 4
// Answer
// 4

// Test: #4, time: 15 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
// Input
// 1
// 0
// 1
// Output
// 1
// Answer
// 1

// Test: #5, time: 0 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
// Input
// 6
// 110110
// 000000
// Output
// 4
// Answer
// 4

// Test: #6, time: 15 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
// Input
// 15
// 101010101010101
// 010101010101010
// Output
// 8
// Answer
// 8