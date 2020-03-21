#include <iostream>
using namespace std;

int sum(int *a, int size)
{
    cout << "SIZE OF a in FUNCTION " << sizeof(a) << endl;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans += a[i];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "SIZE OF a in MAIN " << sizeof(a) << endl;
    cout << sum(a, 10) << " is the sum of 10 elements  " << endl;
    cout << sum(a, 5) << " is the sum of 5 elements  " << endl;
}
