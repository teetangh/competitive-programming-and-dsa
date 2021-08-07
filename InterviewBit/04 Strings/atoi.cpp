// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int atoi(const string A)
{

    bool leadingSpaces = true;
    bool negativeResult = false;
    long int result = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == ' ')
        {
            if (leadingSpaces)
                continue;
            else
                break;
        }
        leadingSpaces = false;

        if (A[i] == '+')
            continue;

        if (A[i] == '-')
        {
            negativeResult = true;
            int nextChar = A[i + 1] - '0';

            if (nextChar >= 0 && nextChar <= 9)
                continue;
            else
                return 0;
        }

        int temp = A[i] - '0';
        if (temp >= 0 && temp <= 9)
        {
            result = result * 10 + temp;
            if (result > INT_MAX)
            {
                if (negativeResult)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }
        else
            break;
    }

    if (negativeResult)
        return -result;
    else
        return (int)result;
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
    cin.ignore();

    string temp;
    while (tc--)
    {
        getline(cin, temp, '\n');
        // cout << temp << endl;
        cout << atoi(temp) << endl;
    }

    return 0;
}
