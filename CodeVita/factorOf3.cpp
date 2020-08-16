#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string printFactor(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (((arr[i] + arr[j]) % 3 == 0))
            {
                int prev_k = arr[0];
                for (int k = 1; (k < arr.size() - 1); k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    if (arr[prev_k] != arr[k])
                        return "Yes";
                    prev_k = k;
                }
            }
            return "No";
        }
    }
    return "Yes";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    int n;
    while (test_cases--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << printFactor(arr) << endl;
        arr.clear();
    }

    return 0;
}
// // Sample IO
// 4
// 4
// 1 2 3 3
// 4
// 1 2 3 4
// 4
// 3 6 1 9
// 3
// 2 7 10

// Yes
// Yes
// Yes
// No
