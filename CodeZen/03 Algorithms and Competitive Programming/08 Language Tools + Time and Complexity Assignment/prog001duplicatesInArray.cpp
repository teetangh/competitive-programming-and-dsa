#include <iostream>
using namespace std;
// #include "solution.h"

#include <bits/stdc++.h>
int DuplicateNumber(int arr[], int size)
{

    map<int, int> mp;

    for (int i = 0; i < size; i++)
        mp[arr[i]]++;

    for (auto &ele : mp)
    {
        if (ele.second > 1)
            return ele.first;
    }
    return -1;
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    cout << DuplicateNumber(input, size);

    delete[] input;

    return 0;
}