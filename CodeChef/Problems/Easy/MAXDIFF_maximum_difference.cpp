#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

typedef long long ll;
typedef long long int lli;

using namespace std;

lli max_diff(vector<lli> vec, lli k)
{
    sort(vec.begin(), vec.end());
    lli child_sum = accumulate(vec.begin(), vec.begin() + k, 0);
    lli chef_sum = accumulate(vec.begin(), vec.end(), 0) - child_sum;

    return chef_sum - child_sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    lli test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        lli n, k;
        cin >> n >> k;

        // In case child gets more , then flip child and chef
        if (k > n / 2)
            k = n - k;

        vector<lli> vec(n);
        for (lli i = 0; i < n; i++)
            cin >> vec[i];

        cout << max_diff(vec, k) << "\n";
        vec.clear();
    }
    return 0;
}
