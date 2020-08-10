// Triple Hunting
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

    int arr[n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 3 == 0)
            count++;
    }

    if (count == 0)
        cout << "Nothing here!";
    else
    {
        cout << count << endl;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 3 == 0)
                cout << i + 1 << " ";
        }
    }
}

// // Sample IO 1
// 7
// 10 12 8 9 3 29 30

// 4
// 2 4 5 7

// // Sample IO 2
// 7

// 16 49 2 10 28 55 31

// Nothing here!