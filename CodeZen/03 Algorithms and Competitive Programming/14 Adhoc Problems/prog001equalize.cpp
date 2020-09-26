#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long ll;
typedef long long int lli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int cost = 0;
    for (int i = 0; i < n;)
    {
        if (s[i] != t[i])
        {
            // Either Swap of flip and increment the cost
            if (i + 1 < n && s[i] != s[i + 1] && s[i + 1] != t[i + 1])
            {
                // swapping
                i += 2;
            }
            else
                i++;
            cost++;
        }
        else
            i++;
    }

    cout << cost << endl;
    return 0;
}
// // Sample IO
// 6
// 110110
// 000000

// 4
