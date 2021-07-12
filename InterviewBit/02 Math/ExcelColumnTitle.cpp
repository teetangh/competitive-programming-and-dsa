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
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

string SolutionconvertToTitle(int A)
{

    int q, r;

    vector<int> Q;
    vector<int> R;

    int letters = 0;
    int temp = A;
    while (temp > 0)
    {
        q = temp / 26, r = temp % 26;
        Q.push_back(q), R.push_back(r);
        temp = q;

        letters++;
    }

    // string result;
    temp = A;
    string result = "";
    for (int i = letters - 1; i >= 0; i--)
    {
        int multiplier = temp / pow(26, i);
        int remainder = temp % (int)pow(26, i);

        result += (('A' + multiplier - 1));
        temp = remainder;
    }

    return result;
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

    while (tc--)
    {
        int num;
        cin >> num;
        cout << SolutionconvertToTitle(num) << endl;
    }

    // cout << static_cast<char>('A' + 3 - 1) << endl;
}
