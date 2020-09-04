#include <iostream>
using namespace std;
// #include "solution.h"

#include <bits/stdc++.h>


// Direct Formula
// O(n) Time | O(1) space
int DuplicateNumber3(int arr[], int size)
{

}

// Sorting the Array
// O(NlogN) Time | O(1) space
int DuplicateNumber2(int arr[], int size)
{

}


// Using Map to store the frequencies
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