#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //code
    int test_cases;
    cin >> test_cases;

    int size;
    while (test_cases--)
    {
        cin >> size;
        int temp = 0;
        int sum = 0;
        for (int i = 0; i < size - 1; i++)
        {
            cin >> temp;
            sum += temp;
        }

        cout << (((size) * (size + 1)) / 2) - sum << endl;
    }

    return 0;
}