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

    string input;
    cin >> input;

    set<char> my_vowels = {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i'};

    string output;
    int output_index = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (my_vowels.find(input[i]) != my_vowels.end())
            continue;
        else
        {
            output += '.';
            if (input[i] >= 'A' && input[i] <= 'Z')
                output += input[i] + 32;
            else if (input[i] >= 'a' && input[i] <= 'z')
                output += input[i];
        }
    }
    cout << output << endl;
}
