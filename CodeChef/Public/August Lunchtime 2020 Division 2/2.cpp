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
        int digits;
        cin >> digits;

        int n;
        int conseq_zero = 0;
        int lonely_zero = 0;

        int longest_conseq_zero = -1;
        int longest_odd_conseq_zero = -1;

        string ans = "No";

        while (digits--)
        {
            cin >> n;
            if (n == 0)
                conseq_zero++;
            else
            {
                if (conseq_zero == 1)
                {
                    lonely_zero++;
                    if (longest_conseq_zero <= 0)
                        longest_conseq_zero = 1;
                }

                if (longest_odd_conseq_zero % 2 != 0)
                    longest_odd_conseq_zero = conseq_zero;

                if (longest_conseq_zero < conseq_zero)
                    longest_conseq_zero = conseq_zero;
            }
        }

        if ((lonely_zero == 0 || lonely_zero >= 2) && longest_conseq_zero == -1 && longest_odd_conseq_zero == -1)
        {
            cout << "No" << endl;
            continue;
        }
        if (lonely_zero == 1 && longest_conseq_zero == -1 && longest_odd_conseq_zero == -1)
        {
            cout << "Yes" << endl;
            continue;
        }
        if (longest_odd_conseq_zero >= longest_conseq_zero)
        {
            cout << "Yes" << endl;
            continue;
        }

        cout << ans << endl;
    }
    return 0;
}
