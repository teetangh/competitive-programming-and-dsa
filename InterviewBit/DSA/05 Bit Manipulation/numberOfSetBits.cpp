// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int numSetBits(unsigned int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    auto B = A;

    int count = 0;
    while (B != 0)
    {
        if ((B & 1) != 0)
            count++;

        B = B >> 1;
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
    // cout << tc;
    unsigned int A;
    while (tc--)
    {
        cin >> A;
        cout << numSetBits(A) << endl;
    }
}
