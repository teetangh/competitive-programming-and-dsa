#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int test_cases;
    cin >> test_cases;

    int arr_size;
    int index;

    while (test_cases--)
    {
        cin >> arr_size;
        vector<int> vec(arr_size);
        for (int i = 0; i < arr_size; i++)
            cin >> vec[i];

        cin >> index;
        int key = vec[index - 1];

        sort(vec.begin(), vec.end());

        cout << lower_bound(vec.begin(), vec.end(), key) - vec.begin() + 1 << endl;
        vec.clear();
    }
    return 0;
}

// Example
// Input:
// 3
// 4
// 1 3 4 2
// 2
// 5
// 1 2 3 9 4
// 5
// 5
// 1 2 3 9 4 
// 1

// Output:
// 3
// 4
// 1
 