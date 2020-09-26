#include <iostream>
using namespace std;

int main()
{
    int y = 0;
    if (1 | (y = 1))
    {
        cout << "y is " << y;
    }
    else
    {
        cout << y;
    }
}
// Output
// y is 1