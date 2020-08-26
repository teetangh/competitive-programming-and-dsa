#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli calculate_digit_sum(lli input)
{
    lli output = 0;

    while (input > 0)
    {
        int last_digit = input % 10;
        output += last_digit;
        input /= 10;
    }
    return output;
}

int main()
{
    // Write your code here
    int test_cases;
    cin >> test_cases;

    lli input;
    while (test_cases--)
    {
        cin >> input;
        cout << calculate_digit_sum(input) << endl;
    }

    return 0;
}