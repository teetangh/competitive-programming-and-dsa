// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int f(int i, int j, vector<int> arr, int k)
{
    return i * j - k * (arr[i] | arr[j]);
}

int cobb(vector<int> arr, int k)
{
    int currF;
    int maxF = INT_MIN;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            currF = f(i, j, arr, k);
            if (currF > maxF)
                maxF = currF;
        }
    }
    return maxF;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        cout << cobb(arr, k) << endl;
    }
}
