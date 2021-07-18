// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    char arr[] = {'A', 'B', 'C', 'D'};
    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        int total = 1 << n;

        for (int mask = 0; mask < total; mask++)
        {
            for (int i = 0; i < n; i++)
            {
                int f = 1 << i;
                if ((mask & f) != 0)
                    cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}

// Sample IO
// 4

// 1
// 2
// 3
// 4

// A

// A
// B
// A B

// A
// B
// A B
// C
// A C
// B C
// A B C

// A
// B
// A B
// C
// A C
// B C
// A B C
// D
// A D
// B D
// A B D
// C D
// A C D
// B C D
// A B C D
