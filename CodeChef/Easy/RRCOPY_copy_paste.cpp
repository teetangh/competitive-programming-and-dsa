#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

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
        set<int> my_set;

        int temp;
        for (int i = 0; i < size; i++)
        {
            cin >> temp;
            my_set.insert(temp);
        }

        cout << my_set.size() << endl;
        my_set.clear();
    }

    return 0;
}