#include <iostream>
#include <vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef long long int lli;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    ll t;
    cin >> t;

    ll num_of_cupcakes;
    while (t--)
    {
        ll num_of_cupcakes;
        cin >> num_of_cupcakes;
        vector<ll> vec(num_of_cupcakes + 1);

        ll max_remainder = -99999;
        ll max_index = 1;
        for (ll i = 1; i <= num_of_cupcakes; i++)
        {
            vec[i] = num_of_cupcakes % i;
            if (vec[i] >= max_remainder)
            {
                max_remainder = vec[i];
                max_index = i;
            }
        }
        cout << max_index << endl;
    }
    return 0;
}
