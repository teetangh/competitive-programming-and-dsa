// Includes
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

typedef long long int lli;
const int MAX_SIZE = 90000000;
bool *is_prime = new bool[MAX_SIZE + 1];

void sieve()
{

    for (lli i = 0; i <= MAX_SIZE; i++)
        is_prime[i] = true;
    is_prime[0] = false, is_prime[1] = false;

    for (lli i = 2; i <= MAX_SIZE; i++)
    {
        if (is_prime[i])
        {
            for (lli j = i * i; j <= MAX_SIZE; j += i)
                is_prime[j] = false;
        }
    }
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

    sieve();
    lli counter = 0;
    lli num = 0;
    lli last_i = -1;

    while (tc--)
    {
        cin >> num;
        for (lli i = last_i + 1; i <= MAX_SIZE; i++)
        {
            if (is_prime[i] == true)
                counter++;
            // cout << "counter " << counter << " " << i << " " << num << endl;
            if (counter == num)
            {
                // cout << counter << " " << i << endl;
                cout << i << endl;
                last_i = i;
                break;
            }
        }
    }
    return 0;
}
