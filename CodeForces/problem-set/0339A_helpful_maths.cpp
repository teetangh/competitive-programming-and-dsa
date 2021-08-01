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
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    priority_queue<int, vector<int>, greater<int>> pq;

    string input;
    cin >> input;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != '+')
            pq.push(input[i]);
    }

    string output;
    while (!pq.empty())
    {
        output += pq.top();
        if (pq.size() != 1)
            output += "+";
        pq.pop();
    }

    // output[output.length() - 1] = '\0';
    cout << output << endl;
}
