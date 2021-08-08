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

// // Sample IO
// 5
// -54332872018247709407 4 54
// 7 U 0 T7165 0128862 089 39 5
// 56
// -6435D56183011M11 648G1 903778065 762 75316456373673B5 334 19885 90668 8 98K X277 9846
// +7

// // Sample Output
// -2147483648
// 7
// 56
// -6435
// 7