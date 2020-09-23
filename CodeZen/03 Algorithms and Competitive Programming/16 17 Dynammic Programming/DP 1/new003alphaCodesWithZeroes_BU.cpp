#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;
typedef long long int lli;

lli num_codes3(lli *input, lli size)
{
    lli *output = new lli[size + 1];
    output[0] = 1;
    output[1] = 1;

    for (lli i = 2; i <= size; i++)
    {
        output[i] = output[i - 1] % MOD;

        // if (input[i - 2] * 10 + input[i - 1] <= 26)
        if ((input[i - 1] <= 6 && input[i - 2] == 2) || input[i - 2] == 1)
            output[i] = (output[i] + output[i - 2]) % MOD;
    }

    lli ans = output[size] % MOD;
    delete[] output;
    return ans % MOD;
}
int main()
{

    string num;
    while (cin >> num)
    {
        if (num == "0")
            break;
        lli *input = new lli[100];
        for (lli i = 0; i < num.length(); i++)
            input[i] = num[i] - '0';

        cout << num_codes3(input, num.length()) << endl;

        delete[] input;
    }
    return 0;
}
