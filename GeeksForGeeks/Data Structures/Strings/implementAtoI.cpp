// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{

    int reverseNum(int num)
    {
        int rev = 0;

        while (num > 0)
        {
            int last = num % 10;
            rev = rev * 10 + last;
            num = num / 10;
        }
        return rev;
    }

public:
    /*You are required to complete this method */
    int atoi(string str)
    {

        int result = 0;
        int trailingZeros = 0;

        int positiveResult = 1;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (i == 0 && str[i] == '-')
            {
                positiveResult = -1;
                break;
            }

            result *= 10;

            if ((str[i] - '0') < 0 || (str[i] - '0') > 9)
                return -1;

            result += str[i] - '0';

            if (result == 0)
                trailingZeros++;
        }

        return positiveResult * reverseNum(result) * pow(10, trailingZeros);
    }
};

// { Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
} // } Driver Code Ends

// // SampleIO
// 4

// 123
// 7890
// -1234
// -705060

// 123
// 7890
// -1234
// -705060
