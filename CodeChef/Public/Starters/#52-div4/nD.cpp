// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define M 64

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

string solve(ulli N, ulli k, string input)
{
    ulli tries = N - k + 1;

    string output = input;
    bitset<N> bs(input);
    for (int i = 0; i < output.size(); i++)
    {
        if (output[i] == '1')
        {
            output = flipAllBits(output, i, i + k - 1);
            tries--;
        }
        if (tries == 0)
            return output;
    }
    return output;
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
        ulli N, k;
        cin >> N >> k;
        string input;
        cin >> input;
        cout << solve(N, k, input) << endl;
    }

    return 0;
}
