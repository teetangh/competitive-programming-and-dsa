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

int solve(vector<int> &arr, int k)
{
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

        // if frequency of any element is more than half of the size, then it is not possible to form a sequence
        unordered_map<int, int> freq;
        for (int i = 0; i < size; i++)
            freq[arr[i]]++;

        bool possible = true;
        for (auto it : freq)
        {
            if (it.second > size - it.second + 1)
            {
                cout << "No" << endl;
                possible = false;
                break;
            }
        }
        if (possible)
            cout << "Yes" << endl;
    }

    return 0;
}
