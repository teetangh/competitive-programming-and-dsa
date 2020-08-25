#include <iostream>
using namespace std;

// #include "solution.h"

#include <bits/stdc++.h>
void rotate(int *input, int d, int n)
{
    queue<int> my_queue;
    //Write your code here
    for (int i = 0; i < n; i++)
        my_queue.push(input[i]);

    for (int i = 0; i < d; i++)
    {
        auto temp = my_queue.front();
        my_queue.pop();
        my_queue.push(temp);
    }

    int i = 0;
    for (auto it = my_queue.front(); it != my_queue.back(); ++it)
    {
        input[i] = (int)*it;
        i++;
    }
    // cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}