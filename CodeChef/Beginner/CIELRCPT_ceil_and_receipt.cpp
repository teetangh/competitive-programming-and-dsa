#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int minimum_num_of_menus(int price)
{
    if (price <= 2048)
    {
        if ((price != 0) && (price & (price - 1) == 0))
            return 1;
        else
        {
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    // cout << test_cases;

    int price;
    while (test_cases--)
    {
        cin >> price;
        cout << minimum_num_of_menus(price) << endl;
    }
}
