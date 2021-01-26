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

    int n, k, count = 0;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < n; i++)
    {
        if ((vec[i] >= vec[k - 1]) && vec[i] > 0)
            count++;
    }

    cout << count << endl;
}
