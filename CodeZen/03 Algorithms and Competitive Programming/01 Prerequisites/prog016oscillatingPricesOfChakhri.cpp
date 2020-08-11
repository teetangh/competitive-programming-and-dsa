#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    // Write your code here
    int array_size;
    cin >> array_size;
    vector<int> arr(array_size);

    int n;
    for (int i = 0; i < array_size; i++)
    {
        cin >> n;
        arr[i] = n;
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < array_size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    cout << max << " " << min << endl;
    cout << (max - min);

    return 0;
}