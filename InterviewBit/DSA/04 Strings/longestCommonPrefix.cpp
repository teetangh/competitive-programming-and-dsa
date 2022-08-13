// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

string longestCommonPrefix(vector<string> &A)
{

    if (A.size() == 1)
        return A[0];

    int minStringLength = INT_MAX;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].size() < minStringLength)
            minStringLength = A[i].size();
    }

    string temp;
    temp = A[0].substr(0, minStringLength);
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j <= minStringLength; j++)
        {
            if (A[i][j] != temp[j])
            {
                minStringLength = j;
                // i--;
                break;
            }
        }
        temp = A[i].substr(0, minStringLength);
    }

    return A[0].substr(0, minStringLength);
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
        int n;
        cin >> n;
        vector<string> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        cout << longestCommonPrefix(A) << endl;
    }
}

// // Sample IO
// 5

// 3
// g g g

// 3
// f g h

// 3
// abcdefgh aefghijk abcefgh

// 3
// abab  ab  abcd

// 3
// abcg abcgsdfg abcgsdfkm

// // OUTPUT
// g

// a
// ab
// abcg
