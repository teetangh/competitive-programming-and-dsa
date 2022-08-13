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
#define mod 1000000007

typedef long long int lli;

int calculateCells(int A, int B, int C)
{

    int days = A;
    int renew = B;
    int ttl = C;

    const int MOD = 1e9 + 7;

    multiset<lli> viruses;
    multiset<lli> newViruses;
    multiset<lli> totalViruses;

    viruses.insert(ttl);

    int renewCounter = 0;
    for (int i = 1; i <= days; i++)
    {
        if (renewCounter == renew)
        {
            for (auto ele : viruses)
            {
                if (ele > 0)
                    newViruses.insert(ttl);
            }

            renewCounter = 0;
        }

        viruses.insert(newViruses.begin(), newViruses.end());
        newViruses.clear();
        
        for (auto ele : viruses)
            ele--;

        renewCounter++;
    }

    int liveCount = 0;
    for (auto ele : viruses)
        liveCount = (liveCount + 1) % MOD;

    return liveCount;
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
        int A, B, C;
        cin >> A >> B >> C;
        cout << calculateCells(A, B, C) << endl;
    }

    return 0;
}
