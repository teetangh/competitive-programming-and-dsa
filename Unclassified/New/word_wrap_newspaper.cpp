// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define watch1(x) cout << (#x) << " is " << (x) << endl
#define watch2(x, y) cout << (#x) << " is " << (x) << " " << (#y) << " is " << (y) << endl
#define mod 1000000007
#define INF 1000000000
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, size) for (int i = 1; i <= size; i++)

// Typedefs
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

string twoColumnOutput(int maxWidth, int lines, string inputTxt)
{

    string result = "";
    int j = 0;

    for (int i = 0; i < inputTxt.size();)
    {
        if (j < maxWidth)
            result += inputTxt[i + j];
        else if (j >= maxWidth && j <= maxWidth + 4)
            result += " ";
        else if (j >= maxWidth + 4 && j <= (2 * maxWidth))
            result += inputTxt[(lines - 1) * maxWidth + i + j];

        j++;
        if (j > 2 * maxWidth)
        {
            j = 0;
            result += '\n';
            i = i + maxWidth + 1;
        }
        if (i >= (lines * maxWidth) - 5 && i <= (lines * maxWidth) + 5)
            result += "\n\n\n\n";
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

    string inputTxt;
    int maxWidth,pages;
    cin >> maxWidth >> pages;
    cin.ignore();
    getline(cin, inputTxt);
    cout << twoColumnOutput(maxWidth, pages, inputTxt);

    return 0;
}
