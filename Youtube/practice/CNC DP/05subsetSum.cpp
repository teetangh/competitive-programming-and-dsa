#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;
    int n, t, sum, p;
    int arr[15];

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> p;

        bool flag = false;
        int tot = 1 << n;
        for (int mask = 0; mask < tot; mask++)
        {
            sum = 0;

            for (int i = 0; i < n; i++)
            {
                int f = 1 << i;
                if ((mask & f) != 0)
                    sum += arr[i];
            }

            if (sum == p)
            {
                flag = true;
                break;
            }
        }

        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
