// Includes
#include <iostream>
#include <iomanip>
#include <string>
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

    fastio;

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int size;
        cin >> size;
        vector<int> vec(size);

        for (int i = 0; i < size; i++)
            cin >> vec[i];

        vector<int> diary_sum(size);

        for (int i = 0; i < size; i++)
        {
            int current_sum = 0;
            for (int j = 0; j < i; j++)
            {
                if (vec[j] < vec[i])
                    current_sum += vec[j];
            }
            diary_sum[i] = current_sum;
        }

        cout << accumulate(diary_sum.begin(), diary_sum.end(), 0) << endl;

        vec.clear();
        diary_sum.clear();
    }
}
