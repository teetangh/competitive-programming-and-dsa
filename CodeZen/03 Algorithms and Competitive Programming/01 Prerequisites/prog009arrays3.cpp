#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int arr[1001];

    // Initailising the friends list with 0 friends each
    for (int i = 0; i < 1001; i++)
    {
        arr[i] = 0;
    }

    // increasing the friend count in the array hashmap
    for (int i = 0; i < n; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        arr[p1]++;
        arr[p2]++;
    }

    // Traversing the array to find the one with max friends
    int max = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    // Printing the player's index with max friends
    for (int i = 0; i < 1001; i++)
    {
        if (arr[i] == max)
        {
            cout << i << endl;
        }
    }

    return 0;
}

// // Sample IO
// 6

// 5 6
// 0 1
// 1 4
// 5 4
// 1 2
// 4 0

// // Output
// 1
// 4
