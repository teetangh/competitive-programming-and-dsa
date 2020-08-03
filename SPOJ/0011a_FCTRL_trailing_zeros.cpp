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

int count_zeros_at_factorial_end2(int num)
{
    int counter = 0;
    for (int i = 1; i <= num; ++i)
    {
        if (i % 5 == 0 )
            counter ++;

    }
    return counter;
}

int count_of_zeroes(std::map<int, int> my_map, int i)
{
    int save_num = i;
    int  factor_2 = 0;
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

int count_zeros_at_factorial_end(int num)
{

    std::map<int, int> my_map;
    int total_count_of_zeroes = 0;
    for (int i = 2; i <= num; i++)
        total_count_of_zeroes += count_of_zeroes(my_map, i);
    return total_count_of_zeroes;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int test_cases;
    cin >> test_cases;
    int test_cases2 = test_cases;

    int n;
    queue<int> mq;
    while (test_cases--)
    {
        cin >> n;
        mq.push(n);
    }
    while (test_cases2--)
    {
        int temp_answer = count_zeros_at_factorial_end2(mq.front());
        mq.pop();
        cout << temp_answer << endl;
    }
}