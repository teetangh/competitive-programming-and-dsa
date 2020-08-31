// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
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

    lli size, variation;
    cin >> size >> variation;

    vector<lli> vec(size);
    for (int i = 0; i < size; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int i = 0;
    int j = 1;

    int count = 0;
    while (i < vec.size() - 1 && j < vec.size())
    {
        if (i >= j)
            j++;
        else if (vec[j] - vec[i] >= variation)
        {
            count += vec.size() - j;
            i++;
        }
        else
            j++;
    }
    cout << count << endl;
    return 0;
}
