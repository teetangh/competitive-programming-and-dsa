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
typedef long long int lli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);   // for getting input from xinput.txt
    freopen("xoutput.txt", "w", stdout); // for writing output to xoutput.txt
#endif

    fastio;

    lli donuts;
    cin >> donuts;

    vector<lli> calories(donuts);

    for (lli i = 0; i < donuts; i++)
        cin >> calories[i];

    sort(calories.begin(), calories.end(), std::greater<lli>());

    lli donuts_eaten = 0;
    lli total_calories = 0;
    for (lli i = 0; i < donuts; i++)
        total_calories += pow(2, i) * calories[i];

    cout << total_calories << endl;
}

// Sample Input
// 3
// 1 3 2
// Sample Output
// 11