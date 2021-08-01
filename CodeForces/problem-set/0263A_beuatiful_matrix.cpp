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

    vector<vector<int>> arr(5, vector<int>(5, 0));

    int one_i, one_j;
    bool flag = false;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                flag = true;
                one_i = i;
                one_j = j;
                break;
            }
        }
        if (flag)
            break;
    }

    cout << abs(one_i - 2) + abs(one_j - 2) << endl;

    return 0;
}
