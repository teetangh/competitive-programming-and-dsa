#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;
typedef long long int lli;

lli output(vector<lli> vec)
{
    lli n = vec.size();
    return (n * (n - 1)) / 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    lli test_cases;
    cin >> test_cases;
    // cout << test_cases;

    lli size;

    while (test_cases--)
    {
        cin >> size;
        vector<lli> vec(size);
        for (lli i = 0; i < size; i++)
            cin >> vec[i];
        cout << output(vec) << endl;
    }
    return 0;
}
