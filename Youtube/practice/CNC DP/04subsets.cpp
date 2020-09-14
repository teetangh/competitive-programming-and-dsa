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

    char ar[] = {'A', 'B', 'C', 'D'};

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int tot = 1 << n;
        for (int mask = 0; mask < tot; mask++)
        {
            for (int i = 0; i < n; i++)
            {
                int f = 1 << i;
                if ((mask & f) != 0)
                    cout << ar[i] << " ";
            }
            cout << endl;
        }
    }
}
// 1

// 4


// A 
// B 
// A B 
// C 
// A C 
// B C 
// A B C 
// D 
// A D 
// B D 
// A B D 
// C D 
// A C D 
// B C D 
// A B C D 