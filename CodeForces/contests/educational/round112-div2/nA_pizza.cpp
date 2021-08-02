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
typedef unsigned long long int ulli;

ulli totalTime(ulli temp)
{
    pair<int, int> small{6, 15};
    pair<int, int> medium{8, 20};
    pair<int, int> large{10, 25};

    ulli totalTime = 0;
    if (temp >= large.first)
    {
        ulli numLargePieces = temp / large.first;
        temp = temp % large.first;

        totalTime += numLargePieces * large.second;
    }

    if (temp >= medium.first)
    {
        ulli numMeidumTests = temp / medium.first;
        temp = temp % medium.first;

        totalTime += numMeidumTests * medium.second;
    }

    if (temp >= small.first)
    {
        ulli numSmallPieces = temp / small.first;
        temp = temp % small.first;

        totalTime += numSmallPieces * small.second;
    }

    if (temp > 0)
        totalTime += small.second;

    return totalTime;
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
        ulli temp;
        cin >> temp;
        cout << totalTime(temp) << endl;
    }
}
