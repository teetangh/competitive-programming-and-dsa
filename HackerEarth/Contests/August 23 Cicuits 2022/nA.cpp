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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    ulli tc;
    cin >> tc;

    while (tc--)
    {
        ulli size;
        cin >> size;
        vector<ulli> arr(size);
        for (ulli i = 0; i < size; i++)
            cin >> arr[i];

        ulli max1 = *max_element(arr.begin(), arr.end());
        ulli min1 = *min_element(arr.begin(), arr.end());

        // find second max and second min
        ulli max2 = 0;
        ulli min2 = 0;
        for (ulli i = 0; i < size; i++)
        {
            if (arr[i] > max2 && arr[i] != max1)
                max2 = arr[i];
            else if (arr[i] < min2 && arr[i] != min1)
                min2 = arr[i];
        }
        cout << max1 << " " << min1 << " " << max2 << " " << min2 << endl;

        cout << (max1 - min1) << " " << (max2 - min2) << endl;
    }

    return 0;
}
