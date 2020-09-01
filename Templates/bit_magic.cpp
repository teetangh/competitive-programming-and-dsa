#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int number;
    cin >> number;

    for (int i = 0; i < 4; i++)
    {
        int temp = number | (1 << i);
        cout << 'i' << i << "temp" << temp << endl;
    }

    return 0;
}
