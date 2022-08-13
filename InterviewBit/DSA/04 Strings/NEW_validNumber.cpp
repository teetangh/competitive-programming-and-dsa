// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int isNumber(const string A)
{
    bool hasSpaces = false;
    bool hasNumber = false;

    if (A.empty())
        return false;

    bool hasE = false;
    bool hasDot = false;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == ' ')
            continue;

        else if (A[i] == '-' && i == 0)
            continue;
        else if (A[i] == '-' && i >= 1 && A[i - 1] == 'e')
            continue;

        else if (A[i] >= '0' && A[i] <= '9')
            continue;

        else if (A[i] == 'e')
        {
            if (!hasE)
            {
                hasE = true;
                continue;
            }
            else
                return false;
        }
        else if (A[i] == '.' && !hasE)
        {

            if (!hasDot && (A[i + 1] == '\0' || A[i + 1] == 'e'))
                return false;
            else if (!hasDot && A[i + 1] != '\0')
            {
                hasDot = true;
                continue;
            }
            else if (hasDot)
                return false;
        }
        else
            return false;
    }

    return true;
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
    cin.ignore();
    string A;
    while (tc--)
    {
        getline(cin, A, '\n');
        cout << A << " ";
        if (isNumber(A))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// 19
//   0.1
// 1.e10
// 0
// abc
// 1 a
// 2e10
// 1u
// 0.1e10
// -01.1e-10
// 0xFF
// 3.
// 3e0.1
// 1f
// 1000LL
// 1000L
// 00
// 0
      
// 008