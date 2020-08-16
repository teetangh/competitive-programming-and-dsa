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
            if ((arr[i] + arr[j]) % 3 == 0 && abs(i - j) != 1)
            {
                return "no";
            }
        }
    }
    return "yes";
}

int main()
{
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
