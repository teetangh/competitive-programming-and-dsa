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
typedef unsigned long long int ulli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n;
    cin >> n;

    unordered_map<ulli, ulli> ump;
    ulli temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ump[temp]++;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ump[temp]--;
    }

    int duplicate = 1;
    for (auto ele : ump)
    {
        if (ele.second != 0)
        {
            duplicate = 0;
            break;
        }
    }

    cout << duplicate << endl;
}
