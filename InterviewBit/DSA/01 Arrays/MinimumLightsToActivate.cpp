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

int solve(vector<int> &lights, int power)
{
    vector<bool> corridor(lights.size(), false);

    int minLights = 0;
    for (int i = 0; i < corridor.size(); i++)
    {
        if (corridor[i] == false)
        {
            bool doneLighting = false;
            for (int j = i + power - 1; j >= i - power + 1; j--)
            {
                if (lights[j] == 1)
                {
                    for (int k = j - power + 1; k <= j + power - 1; k++)
                    {
                        if (k >= 0 && k < corridor.size())
                            corridor[k] = true;
                    }
                    minLights++;
                    doneLighting = true;
                    break;
                }
            }
            if (!doneLighting)
                return -1;
        }
    }

    return minLights;
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

    while (tc--)
    {
        int size;
        cin >> size;
        vector<int> lights(size);
        for (int i = 0; i < size; i++)
            cin >> lights[i];

        int power;
        cin >> power;

        cout << solve(lights, power) << endl;
    }
}
