#include <bits/stdc++.h>
using namespace std;

// Defines
#define MOD 1000000007
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

lli increasing_subsequence_GCD1(vector<lli> &vec)
{
    vector<vector<lli>> dp;
    dp.resize(vec.size(), vector<lli>(101, 0));

    // dp[1][__gcd(vec[0], vec[1])]++;

    for (lli i = 0; i < vec.size(); i++)
        dp[i][vec[i]] = 1;

    for (lli i = 1; i < vec.size(); i++)
    {
        for (lli k = i - 1; k >= 0; k--)
        {
            if (vec[k] < vec[i])
            {
                for (lli g = 1; g <= 100; g++)
                {
                    lli new_gcd = __gcd(vec[i], g);
                    dp[i][new_gcd] += dp[k][g];
                }
            }
        }
    }

    // for (auto &ele : dp)
    // {
    //     for (auto &ele2 : ele)
    //         cout << ele2 << " ";
    //     cout << endl;
    // }

    lli sum_gcd1 = 0;
    for (lli i = 0; i < vec.size(); i++)
        sum_gcd1 += dp[i][1];

    return sum_gcd1 % MOD;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("xinput.txt", "r", stdin);
    //     freopen("xoutput.txt", "w", stdout);
    // #endif

    fastio;
    lli N;
    cin >> N;

    vector<lli> vec(N);

    for (lli i = 0; i < N; i++)
        cin >> vec[i];

    cout << increasing_subsequence_GCD1(vec) << endl;

    return 0;
}
// Sample Input
// 3
// 1 2 3
// Sample Output
// 5

// //  List of MY errors
// 1.  for (int i = 0; i < vec.size(); i++)
//         dp[i][vec[i]] = 1;

// 2. // dp[1][__gcd(vec[0], vec[1])]++;

// 3. for (int i = 1; i < vec.size(); i++)   [earlier i = 2]

// 4. where to put MOD ???

