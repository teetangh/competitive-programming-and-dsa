#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using namespace std;

int min_num_of_moves(vector<int> my_vec)
{
    auto min = *min_element(my_vec.begin(), my_vec.end());
    vector<int> min_vector(my_vec.size(), min);

    int sum = 0;
    for (int i = 0; i < my_vec.size(); i++)
        sum += (my_vec[i] - min_vector[i]);

    return sum;
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
    // cout << test_cases;

    int arr_size;
    while (test_cases--)
    {
        cin >> arr_size;
        vector<int> my_vec(arr_size);
        for (int i = 0; i < arr_size; i++)
            cin >> my_vec[i];

        cout << min_num_of_moves(my_vec) << endl;
        my_vec.clear();
    }
    return 0;
}
