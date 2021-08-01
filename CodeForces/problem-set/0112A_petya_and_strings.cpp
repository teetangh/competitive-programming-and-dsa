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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
#endif

    fastio;

    string input1, input2;
    cin >> input1 >> input2;

    int answer = 0;
    for (int i = 0; i < input1.length(); i++)
    {
        if (input1[i] >= 'A' && input1[i] <= 'Z')
            input1[i] += 32;
        if (input2[i] >= 'A' && input2[i] <= 'Z')
            input2[i] += 32;

        if (input1[i] > input2[i])
        {
            answer = 1;
            break;
        }
        else if (input1[i] < input2[i])
        {
            answer = -1;
            break;
        }
    }
    cout << answer << endl;
}
