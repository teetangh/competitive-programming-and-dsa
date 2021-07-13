// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

typedef long long int lli;

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
        int N;
        cin >> N;

        vector<int> vec(N, 0);
        for (int i = 1; i < N; i++)
            cin >> vec[i];

        lli acutalSum = std::accumulate(vec.begin() + 1, vec.end(), 0);
        lli realSum = N * (N + 1) / 2;

        cout << realSum - acutalSum << endl;
        vec.clear();
    }
}
