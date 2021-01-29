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

int kadane(vector<int> arr, int n)
{
    int current_sum = 0;
    int best_sum = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum = current_sum + arr[i];
        if (current_sum > best_sum)
            best_sum = current_sum;
        if (current_sum < 0)
            current_sum = 0;
    }
    return best_sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << kadane(arr, n) << endl;
}

// // Sample IO
// 8
// -2  -3  4  -1  -2  1  5  -3

// 7
