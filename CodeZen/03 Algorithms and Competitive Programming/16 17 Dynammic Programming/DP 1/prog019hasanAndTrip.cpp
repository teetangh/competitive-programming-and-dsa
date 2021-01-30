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

class city
{
public:
    int X;
    int Y;
    int F;

    double distance(const city &C2) const
    {
        return abs(sqrt((pow((C2.X - this->X), 2) + pow((C2.Y - this->Y), 2))));
    }
};

double max_happiness(const vector<city> &cities)
{

    vector<double> dp(cities.size(), -9999999);

    dp[0] = cities[0].F;

    for (int i = 1; i < cities.size(); i++)
    {
        auto destination_city = cities[i];
        dp[i] = INT_MIN;

        for (int j = i - 1; j >= 0; j--)
        {
            auto current_city = cities[j];
            double current_happiness = destination_city.F - current_city.distance(destination_city);

            if (dp[j] + current_happiness > dp[i])
                dp[i] = dp[j] + current_happiness;
        }
    }

    // for (auto &ele : dp)
    //     cout << ele << " ";
    // cout << "\n===========\n";

    return dp[cities.size() - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    int N;
    cin >> N;

    vector<city> cities(N);
    for (int i = 0; i < N; i++)
        cin >> cities[i].X >> cities[i].Y >> cities[i].F;

    // cout << max_happiness(cities) << endl;
    printf("%6f", max_happiness(cities));
}

// Sample Input
// 3
// 0 0 1
// 3 1 1
// 6 0 9
// Sample Output
// 4.675445