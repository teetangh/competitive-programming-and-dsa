#include <bits/stdc++.h>
using namespace std;

// Defines
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// typedefs
typedef long long ll;
typedef long long int lli;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    lli Nshops, Qdays, Xsaved;

    cin >> Nshops;
    vector<lli> shops(Nshops);
    for (lli i = 0; i < Nshops; i++)
        cin >> shops[i];

    cin >> Qdays;
    vector<lli> days(Qdays);
    for (lli i = 0; i < Qdays; i++)
        cin >> days[i];

    vector<pair<lli, lli>> output;
    // (Qdays);

    for (lli i = 0; i < Qdays; i++)
    {
        lli current_shop_counter = 0;
        for (lli j = 0; j < Nshops; j++)
        {
            if (days[i] >= shops[j])
            {
                current_shop_counter++;
                days[i] = days[i] - shops[j];

                if (days[i] == 0)
                    break;
            }
            else
                break;
        }
        output.push_back(std::make_pair(current_shop_counter, days[i]));
    }

    for (auto &ele : output)
        cout << ele.first << " " << ele.second << endl;

    return 0;
}

// // Sample IO

// 10
// 6 8 11 0 0 13 3 11 0 5 
// 9
// 5
// 18
// 34
// 9
// 29
// 1
// 18
// 1
// 1

// Expected Output
// 0 5
// 2 4
// 5 9
// 1 3
// 5 4
// 0 1
// 2 4
// 0 1
// 0 1