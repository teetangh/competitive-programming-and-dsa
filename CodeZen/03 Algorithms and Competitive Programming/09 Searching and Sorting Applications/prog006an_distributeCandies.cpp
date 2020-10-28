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

bool check_distribution(vector<int> candy_vector, int candies, int Kstudents)
{
    int count = 0;
    for (auto ele : candy_vector)
    {
        count += ele / candies;
        if (count >= Kstudents)
            return true;
    }
    return false;
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
        int Ncandy_boxes, Kstudents;
        cin >> Ncandy_boxes >> Kstudents;

        vector<int> candy_vector(Ncandy_boxes);
        for (int i = 0; i < Ncandy_boxes; i++)
            cin >> candy_vector[i];

        // int total_sum = accumulate(candy_vector.begin(),candy_vector.end(),0);
        int max = *max_element(candy_vector.begin(), candy_vector.end());
        int min = *min_element(candy_vector.begin(), candy_vector.end());

        bool flag = false;
        for (int i = max; i >= min; i--)
        {
            if (check_distribution(candy_vector, i, Kstudents))
            {
                cout << i << endl;
                flag = true;
                break;
            }
        }

        if (flag == false)
            cout << min << endl;

        candy_vector.clear();
    }
}
