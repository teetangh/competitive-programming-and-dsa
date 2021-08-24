// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl

int solve(vector<int> &arr)
{
    int iteration = 0;
    int n = arr.size();

    while (true)
    {
        bool changed = false;
        if (iteration % 2 == 0) // odd
        {
            for (int i = 1; i <= n - 2; i = i + 2)
            {
                if (arr[i - 1] > arr[i])
                    swap(arr[i - 1], arr[i]), changed = true;
            }
        }
        else
        {
            for (int i = 2; i <= n - 1; i = i + 2)
            {
                if (arr[i - 1] > arr[i])
                    swap(arr[i - 1], arr[i]), changed = true;
            }
        }

        if (!changed)
            break;
        iteration++;
    }

    return iteration;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int size;
        cin >> size;
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
            cin >> arr[i];

        cout << solve(arr) << endl;
    }

    return 0;
}
