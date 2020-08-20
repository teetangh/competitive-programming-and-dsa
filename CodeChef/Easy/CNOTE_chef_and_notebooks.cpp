#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

void determine_luck(int x, int y, int k, int n, vector<pair<int, int>> vp)
{
    int diff_in_pages = 0;
    if (x > y)
        diff_in_pages = (x - y);

    for (auto &ele : vp)
    {
        if (ele.first >= diff_in_pages && ele.second <= k)
        {
            cout << "LuckyChef" << endl;
            return;
        }
    }
    cout << "UnluckyChef" << endl;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    int x, y, k, n;
    while (test_cases--)
    {
        cin >> x >> y >> k >> n;
        vector<pair<int, int>> vp;

        int pi, ci;
        for (int i = 0; i < n; i++)
        {
            cin >> pi >> ci;
            vp.emplace_back(std::make_pair(pi, ci));
        }
        determine_luck(x, y, k, n, vp);
        vp.clear();
    }
}
