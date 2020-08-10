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

    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < q; i++)
    {
        int page;
        cin >> page;
        cout << arr[page - 1] << endl;
    }

    return 0;
}


// // Sampe IO
// 6 5

// 1151
// 723
// 1321
// 815
// 780
// 931

// 4
// 3
// 4
// 5
// 1

// // Output:
// 815
// 1321
// 815
// 780
// 1151
