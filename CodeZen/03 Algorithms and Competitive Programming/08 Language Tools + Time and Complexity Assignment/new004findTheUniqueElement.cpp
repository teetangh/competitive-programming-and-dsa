#include <iostream>
#include <algorithm>
// #include "solution.h"
using namespace std;

// arr - input array
// size - size of array
#include <bits/stdc++.h>

// Using the EXOR Operation
// 
int FindUnique4(int arr[], int size)
{
}

// Sorting the Array
// 
int FindUnique4(int arr[], int size)
{
}

// Maintaing a map
// 
int FindUnique2(int arr[], int size)
{

    map<int, int> mp;

    for (int i = 0; i < size; i++)
        mp[arr[i]]++;

    for (auto &ele : mp)
    {
        if (ele.second == 1)
            return ele.first;
    }

    return -1;
}

// Traversing the Array
// 
int FindUnique(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        bool flag = false;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return arr[i];
    }

    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int size;

    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << FindUnique(input, size) << endl;

    return 0;
}
