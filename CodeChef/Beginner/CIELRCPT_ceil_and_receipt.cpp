#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int minimum_num_of_menus(int price)
{

    if ((price != 0) && (price & (price - 1) == 0) && price <= 2048)
        return 1;
    else
    {
        int i = 11;
        int menu_count = 0;
        while (price > 0)
        {
            if (price >= pow(2, i))
            {
                menu_count++;
                price -= pow(2, i);
                i++;
            }
            i--;
        }
        return menu_count;
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
// Sample Input
// 4
// 10
// 256
// 255
// 4096
// Sample Output
// 2
// 1
// 8
// 2