// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int firstMissingPositive(vector<int> &arr)
{

    int n = arr.size();

    if (n == 0)
        return 1;

    // Your code here
    sort(arr.begin(), arr.end());

    int smallestInteger = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
            continue;

        else if (arr[i] == smallestInteger)
            smallestInteger++;
        else if (arr[i] == smallestInteger - 1)
            continue;
        else if (arr[i] != smallestInteger && arr[i] != smallestInteger - 1)
            return smallestInteger;
    }
    return smallestInteger;
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
    // cout << tc;

    while (tc--)
    {
        int size;
        cin >> size;
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
            cin >> arr[i];

        cout << firstMissingPositive(arr) << endl;
    }
}

// Example:

// Given [1,2,0] return 3,

// [3,4,-1,1] return 2,

// [-8, -7, -6] returns 1