#include <iostream>
using namespace std;

int staircase(int n)
{
    int x, y, z;
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    else
    {

        x = staircase(n - 1);

        y = staircase(n - 2);

        z = staircase(n - 3);
    }

    return x + y + z;
}

int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
}
