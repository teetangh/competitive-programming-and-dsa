#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

typedef long long int lli;

int stable_value(vector<lli> vec)
{
    // bool equal = std::count_if(vec.begin(), vec.end(), [&vec](auto size) { return size == vec[0]; }) == vec.size();
    while (!(std::count_if(vec.begin(), vec.end(), [&vec](auto size) { return size == vec[0]; }) == vec.size()))
    {
        auto max = max_element(vec.begin(), vec.end());
        auto min = min_element(vec.begin(), vec.end());

        *max = *max - *min;
    }

    return vec[0];
}

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
        int size;
        cin >> size;
        vector<lli> vec(size);
        for (int i = 0; i < size; i++)
            cin >> vec[i];

        cout << stable_value(vec) << endl;
    }

    return 0;
}
