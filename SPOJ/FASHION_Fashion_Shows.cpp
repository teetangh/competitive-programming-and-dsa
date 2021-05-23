#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printVOV(vector<vector<int>> my_vec)
{
    for (auto &vec : my_vec)
    {
        for (auto &ele : vec)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

int elementwise_sum_of_2_vectors(vector<int> v1, vector<int> v2)
{
    vector<int> v3(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), std::multiplies<int>());

    int element_wise_sum = accumulate(v3.begin(), v3.end(), 0);

    return element_wise_sum;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    int test_cases2 = test_cases;

    vector<int> vec;
    vector<vector<int>> my_vec;

    while (test_cases--)
    {
        int num_of_participants;
        cin >> num_of_participants;

        vec.clear();
        int sub_test_cases = 2;
        while (sub_test_cases--)
        {
            int x;
            vec.clear();
            for (int i = 0; i < num_of_participants; i++)
            {
                cin >> x;
                vec.push_back(x);
            }
            sort(vec.begin(), vec.end());
            my_vec.push_back(vec);
        }
    }
    // printVOV(my_vec);

    queue<int> mq;

    for (int i = 0; i < test_cases2; i++)
    {
        // int current_sum = 0;
        mq.push(elementwise_sum_of_2_vectors(my_vec[2 * i], my_vec[(2 * i) + 1]));
    }

    while (!mq.empty())
    {
        int temp = mq.front();
        mq.pop();
        cout << temp << endl;
    }

    return 0;
}
