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
#define MAX 1001

vector<int> arr[MAX];
const int maxLevels = 10;
int level[MAX], dp[MAX][maxLevels + 1];

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

    int n, a, b, q;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int size;
        cin >> size;
        vector<int> arr(size);
        for (int i = 0; i < size; i++)
            cin >> arr[i];

        int k;
        cin >> k;
        cout << solve(arr, k) << endl;
    }

    return 0;
}
