#include <iostream>
using namespace std;
// #include "solution.h"

// arr - input array
// size - size of array
// x - sum of triplets
#include <bits/stdc++.h>
void sorted_display(int a, int b, int c)
{
    vector<int> temp_vec;
    temp_vec.clear();
    temp_vec.emplace_back(a);
    temp_vec.emplace_back(b);
    temp_vec.emplace_back(c);

    sort(temp_vec.begin(), temp_vec.end());
    for (auto &ele : temp_vec)
        cout << ele << " ";
    cout << "\n";
    temp_vec.clear();
}

void FindTriplet(int arr[], int size, int x)
{
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == x && i != j && j != k && i != k)
                {
                    sorted_display(arr[i], arr[j], arr[k]);
                }
            }
        }
    }
}

int main()
{

    int size;

    int x;
    cin >> size;

    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];
    cin >> x;

    FindTriplet(input, size, x);

    return 0;
}
