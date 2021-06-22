#include <bits/stdc++.h>

using namespace std;

int main()
{
    //code

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int size;
        cin >> size;

        vector<int> vec(size);
        stack<int> leaders;

        for (int i = 0; i < size; i++)
            cin >> vec[i];

        int curr_max = INT_MIN;

        for (int i = size - 1; i >= 0; i--)
        {
            if (vec[i] >= curr_max)
            {
                curr_max = vec[i];
                leaders.push(vec[i]);
            }
        }

        while (!leaders.empty())
        {
            auto front = leaders.top();
            cout << front << " ";
            leaders.pop();
        }
        cout << endl;

        vec.clear();
        while (!leaders.empty())
            leaders.pop(); // leaders.clear();
    }

    return 0;
}