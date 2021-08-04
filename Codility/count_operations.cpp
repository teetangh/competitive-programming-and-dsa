// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int solution(string &S)
{

    int count = 0;
    int leadZeroCount = 0;
    // Count leading zeroes in string
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '0')
            leadZeroCount++;
        else
            break;
    }

    if (S.length() == leadZeroCount)
        return 0;

    while (!S.empty())
    {
        int zeroCount = 0;

        // check if string contains all zeros C++
        // for (int i = 0; i < S.length(); i++)
        // {
        //     if (S[i] == '0')
        //         zeroCount++;
        //     else
        //         break;
        // }
        // if (zeroCount == S.length())
        //     return count;

        char result = (S[S.size() - 1] - '0') & (1) + '0';
        if (result == 0) // even
        {
            if (S.length() == leadZeroCount + 1)
                break;
            S.pop_back();
        }
        else // odd
        {
            for (int i = S.size() - 1; i >= 0; i--)
            {
                // cout << " debug ";
                if (S[i] == '1')
                {
                    S[i] = '0';
                    break;
                }
                else
                    S[i] = '1';
            }
        }
        count++;
    }
    return count;
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
        string S;
        cin >> S;
        cout << solution(S) << endl;
    }
    // for (size_t i = 0; i < 1000000000; i++)
    // {
    //     /* code */
    //     cout << "1";
    // }
}

// // Sample IO

// 5

// 1

// 00000000

// 000000000000000000011100
// 1111010101111
// 1 repeated 400k times
// 1 repeated 1M times

// // OUTPUT
// 1
// 0
// 7
// 22
// 799999
// 138542573
