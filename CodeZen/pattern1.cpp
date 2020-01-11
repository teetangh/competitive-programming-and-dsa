#include <iostream>
using namespace std;

void printPatt(int n)
{
    //write your code here
    int masterCount = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {

            for (int j = 1; j <= 1; j++)
            {
                cout << j;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    printPatt(n);
}
