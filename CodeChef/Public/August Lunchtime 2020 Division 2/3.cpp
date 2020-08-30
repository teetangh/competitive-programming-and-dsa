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

// typedefs
typedef long long ll;
typedef long long int lli;

class player
{

public:
    vector<int> scores;

    player()
    {
    }

    player(int months)
    {
        for (int i = 0; i < months; i++)
            this->scores[i] = 0;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int Nplayers, months;
        cin >> Nplayers >> months;

        player *arr = new player[Nplayers];
        for (int i = 0; i < Nplayers; i++)
            
        
    }
}
