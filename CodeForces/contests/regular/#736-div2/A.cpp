// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

pair<int, int> solve(int num)
{
    unordered_map<int, int> ump;

    for (int i = 2; i < num; i++)
    {
        if (ump[num % i] != 0)
            return {ump[num % i], i};

        ump[num % i] = i;
    }

    return {};
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
    // cout << tc;

    int num;

    while (tc--)
    {
        cin >> num;
        auto answer = solve(num);
        cout << answer.first << " " << answer.second << endl;
    }
}
