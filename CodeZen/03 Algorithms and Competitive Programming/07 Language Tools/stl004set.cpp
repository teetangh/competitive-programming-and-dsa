#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    set<int> s;
    int arr[] = {1, 2, 3, 4, 5, 6, 5};

    for (int i = 0; i < 7; i++)
        s.insert(arr[i]);

    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); it++)
        cout << *it << endl;

    if (s.find(7) == s.end())
        cout << "Element not found " << endl;
    else
        cout << "Element Found";

    return 0;
}
