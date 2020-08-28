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

#define print_vec            \
    for (auto &ele : vec)    \
        cout << ele << "  "; \
    cout << endl

// typedefs
typedef long long ll;
typedef long long int lli;

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
        lli N, Q;
        cin >> N >> Q;

        vector<lli> vec(N);
        vec.clear();

        // print_vec;

        lli l, r, V;
        int total_raise = 0;
        for (lli i = 0; i < Q; i++)
        {
            // print_vec;
            cin >>
                l >> r >> V;
            for (int j = l; j <= r; j++)
            {
                total_raise += V;
                vec[j] += V;
            }
        }

        // print_vec;

        cout << total_raise << endl;
        vec.clear();
    }
    return 0;
}
