#include <iostream>
// #include "solution.h"

#include <bits/stdc++.h>
#include <climits>
using namespace std;

int *stockSpan(int *input, int size)
{
    int *output = new int[size];

    stack<int> my_stack;

    for (int i = 0; i < size; i++)
    {
        if (my_stack.empty())
            my_stack.push(i);
        else if (input[i] < my_stack.top())
        {
        }
    }
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}