#include <iostream>
using namespace std;

typedef long long int lli;

lli calculate_power(lli base, lli power)
{

    if (base == 1 || power == 0)
        return 1;
    else if (base == 0)
        return 0;
    else
        return base * calculate_power(base, --power);
}

int main()
{
    // Write your code here
    lli base, power;
    cin >> base >> power;
    cout << calculate_power(base, power) << endl;
    return 0;
}
