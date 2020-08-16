#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int subset(vector<int> input, int n, vector<vector<int>> output)
{
    if (n <= 0)
    {
        output[0][0] = 0;
        return 1;
    }

    else
    {
        int smallOutputSize = subset(vector<int>(input.begin() + 1, input.end()), n - 1, output);
        int i, j;
        for (i = 0; i < smallOutputSize; i++)
        {
            output[i + smallOutputSize][0] = output[i][0] + 1;
            output[i + smallOutputSize][1] = input[0];

            for (j = 0; j < output[smallOutputSize + i][0]; j++)
            {
                output[smallOutputSize + i][j + 2] = output[i][j + 1];
            }
        }

        return 2 * smallOutputSize;
    }
}

void subsetCaller()
{
    int length;
    cin >> length;
    std::vector<int> input(length);

    for (int i = 0; i < length; ++i)
        cin >> input[i];

    int default_value = 0;
    vector<vector<int>> output;
    output.resize(pow(2, length), vector<int>(length, default_value));

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0] && output[i][0] == input.size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        subsetCaller();
    }

    return 0;
}
