#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; count < n; i++)
    {
        if ((3 * i + 2) % 4 == 0)
            continue;
        cout << (3 * i + 2) << " ";
        count++;
    }
}
