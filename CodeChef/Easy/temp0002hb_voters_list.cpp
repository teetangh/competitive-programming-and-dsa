#include <bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int size1, size2, size3;
    cin >> size1 >> size2 >> size3;
    int total_list_size = size1 + size2 + size3;
    map<int, int> mp;
    int n;
    for (int i = 0; i < total_list_size; i++)
    {
        cin >> n;
        mp[n]++;
    }
    int count = 0;
    vector<int> result;
    for (auto &ele : mp)
    {
        if (ele.second >= 2)
            result.emplace_back(ele.first);
    }
    cout << result.size() << endl;
    for (auto &ele : result)
    {
        cout << ele << endl;
    }
    return 0;
}