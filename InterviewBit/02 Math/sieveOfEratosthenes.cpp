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

vector<int> sieve(int n)
{

    vector<int> arr(n + 1);
    for (int i = 0; i <= n; i++)
        arr[i] = 1;

    arr[0] = arr[1] = 0;
    arr[2] = 1;

    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j = j + i)
        {
            if (j % i == 0)
                arr[j] = 0;
        }
    }

    vector<int> result;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1)
            result.push_back(i);
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int tc, n;
    cin >> tc;
    // cout << tc;

    while (tc--)
    {
        cin >> n;
        auto result = sieve(n);
        for (auto ele : result)
            cout << ele << " ";
        cout << endl;
    }
}
