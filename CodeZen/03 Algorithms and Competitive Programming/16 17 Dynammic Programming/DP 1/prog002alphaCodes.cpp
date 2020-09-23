#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int num_codes(int *input, int size)
{
    if (size == 1)
        return 1;

    if (size == 0)
        return 1;

    int output = num_codes(input, size - 1);

    if (input[size - 2] * 10 + input[size - 1] <= 26)
        output += num_codes(input, size - 2);

    return output;
}

int num_codes2(int *input, int size, int *arr)
{
    if (size == 1)
        return 1;

    if (size == 0)
        return 1;

    if (arr[size] > 0)
        return arr[size];

    int output = num_codes(input, size - 1);

    if (input[size - 2] * 10 + input[size - 1] <= 26)
        output += num_codes(input, size - 2);

    arr[size] = output;
    return output;
}

int num_codes3(int *input, int size)
{
    int *output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;

    for (int i = 2; i <= size; i++)
    {
        output[i] = output[i - 1];

        if (input[i - 2] * 10 + input[i - 1] <= 26)
            output[i] += output[i - 2];
    }

    int ans = output[size];
    delete[] output;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int *input = new int[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];

    cout << num_codes(input, n) << endl;

    int *arr = new int[n];
    cout << num_codes2(input, n, arr) << endl;
    cout << num_codes3(input, n) << endl;
}
// Sample IO
// 4
// 1 2 3 4 

// 3
// 3
// 3
