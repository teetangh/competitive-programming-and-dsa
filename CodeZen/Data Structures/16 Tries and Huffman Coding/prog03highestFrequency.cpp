#include <iostream>
using namespace std;
// #include "solution.h"

#include <bits/stdc++.h>

int highestFrequency(int *input, int n)
{
    unordered_map<int, int> table;
    for (int i = 0; i < n; i++)
        table[input[i]]++;

    // auto it = table.begin();
    // int maxKey = it->first;

    // for (auto it = table.begin(); it != table.end(); it++)
    //     cout << it->first << " " << it->second << endl;

    int maxKey = input[0];

    for (int i = 0; i < n; i++)
    {
        if (table[maxKey] < table[input[i]])
            maxKey = input[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (table[input[i]] == table[maxKey])
            return input[i];
    }

    // return maxKey;
}

int main()
{
    int n;
    int input[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int maxKey = highestFrequency(input, n);
    cout << maxKey;
    return 0;
}
