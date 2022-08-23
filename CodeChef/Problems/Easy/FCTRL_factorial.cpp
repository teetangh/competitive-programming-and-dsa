/////////////////////////////
/* MY DEFINES*/
// data types
// #define long long ll
// // functions
// #define FOR(0,count) for (int i = 0; i < count; ++i)

/////////////////////////////

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int factorial_trailing_zeroes3(int num)
{
    int counter2 = 0;
    int counter5 = 0;
    int counter10 = 0;

    int safe_i;
    for (int i = 1; i <= num; ++i)
    {
        safe_i = i;

        while (i % 10 == 0)
        {
            counter10++;
            i = i / 10;
        }

        while (i % 2 == 0)
        {
            counter2++;
            i = i / 2;
        }

        while (i % 5 == 0)
        {
            counter5++;
            i = i / 5;
        }

        i = safe_i;
    }

    return counter10 + min(counter2, counter5);
}

int factorial_trailing_zeroes2(int num)
{
    int counter2 = 0;
    int counter5 = 0;
    int counter10 = 0;
    for (int i = 1; i <= num; ++i)
    {
        if (i % 10 == 0)
            counter10++;

        else
        {
            if (i % 2 == 0)
                counter2++;

            if (i % 5 == 0)
                counter5++;
        }
    }

    return counter10 + min(counter2, counter5);
}

int factorial_trailing_zeroes1(std::map<int, int> my_map, int i)
{
    int save_num = i;
    int factor_2 = 0;
    int factor_5 = 0;
    int current_count_of_zeroes = 0;
    while (i % 2 == 0 || i % 5 == 0)
    {
        auto it = my_map.find(i);
        if (it != my_map.end())
        {
            current_count_of_zeroes += std::min(factor_2, factor_5);
            return current_count_of_zeroes;
        }
        else
        {
            if (i % 2 == 0)
            {
                factor_2++;
                i /= 2;
            }
            if (i % 5 == 0)
            {
                factor_5++;
                i /= 5;
            }
        }
    }

    current_count_of_zeroes = std::min(factor_2, factor_5);
    my_map.insert({save_num, current_count_of_zeroes});
    return current_count_of_zeroes;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    int test_cases2 = test_cases;

    int n;
    queue<int> mq;
    while (test_cases--)
    {
        cin >> n;
        cout << factorial_trailing_zeroes3(n) << endl;
    }
}