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

    int tc;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        int temp;
        unordered_map<int, int> ump;
        for (int i = 0; i <= m; i++)
        {
            // arr[i] = n ^ i;
            temp = n ^ i;
            ump[temp]++;
        }

        // int count = 0;
        int i;
        for (i = 0; i <= m; i++)
        {
            if (ump[i] == 0)
                break;
        }
        cout << i << endl;
    }
    return 0;
}
