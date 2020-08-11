#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int array_size;
    cin >> array_size;
    vector<int> arr(array_size);

    for (int i = 0; i < array_size; i++)
        cin >> arr[i];

    int current_max = arr[0];
    int current_min = arr[array_size - 1];

    int current_difference = INT_MIN;

    for (int i = 0; i < array_size; i++)
    {
        for (int j = array_size - 1; j > i; j--)
        {
            if (arr[j] - arr[i] > current_difference)
                current_difference = arr[j] - arr[i];
        }
    }

    cout << current_difference;
    return 0;
}
// // Sample IO 
// 7
// 62 63 70 66 64 68 61

// 8