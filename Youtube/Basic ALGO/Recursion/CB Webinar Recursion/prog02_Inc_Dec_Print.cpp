#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void incPrint(int n)
{
    if (n == 0)
        return;
    incPrint(n - 1);
    cout << n << " ";
}

void decPrint(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    decPrint(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    incPrint(n);
    cout << endl;
    decPrint(n);
    return 0;
}
// // Sample IO
// 10
// 1 2 3 4 5 6 7 8 9 10 
// 10 9 8 7 6 5 4 3 2 1