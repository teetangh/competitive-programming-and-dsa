// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007

// typedefs
typedef long long ll;
typedef long long int lli;

lli counter;

void printHelperFunction(string input, string output)
{
    char leftRecursion, rightRecursion;

    if (input.length() == 0)
    {
        counter %= MOD;
        counter++;
        // cout << output << endl;
        return;
    }

    leftRecursion = 'a' + (input[0] - 48) - 1;

    bool flag = false;
    if (input[1] != '\0')
    {
        rightRecursion = 'a' + (10 * (input[0] - 48) + (input[1] - 48)) - 1;
        if (rightRecursion >= 'a' && rightRecursion <= 'z')
            flag = true;
    }

    printHelperFunction(input.substr(1), output + leftRecursion);
    string output2 = output + rightRecursion;
    if (flag == true)
    {
        printHelperFunction(input.substr(2), output2);
    }
}

void printAllPossibleCodes(string input)
{
    counter = 0;
    string output = "";
    printHelperFunction(input, output);
    cout << counter % MOD << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    while (test_cases--)
    {
        string input;
        cin >> input;
        printAllPossibleCodes(input);
    }
}
