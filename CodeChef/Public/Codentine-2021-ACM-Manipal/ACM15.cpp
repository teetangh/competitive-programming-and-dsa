// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 1; i <= n; i++)
#define INF 1000000000
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int ele;
    cin >> ele;
    unordered_map<int, pair<int, int>> ump;

    bool found = false;
    int temp;

    int answerValue = -1;
    int answerIndex = INT_MAX;

    for (size_t i = 0; i < ele; i++)
    {
        cin >> temp;
        ump[temp].second++;

        if (ump[temp].second == 1)
            ump[temp].first = i;

        if ((ump[temp].second > (ele / 2 + 1)) && ump[temp].first < answerIndex)
        {
            answerValue = temp;
            answerIndex = ump[temp].first;
            found = true;

            break;
        }
    }

    if (!found)
        cout << -1 << endl;
    else
        cout << answerValue << endl;
}
