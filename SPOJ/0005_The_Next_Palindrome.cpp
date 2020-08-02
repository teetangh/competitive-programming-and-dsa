#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int next_palindrome(int current_number)
{
    int num_of_digits = 0;
    int memory = current_number;
    while (memory > 0)
    {
        memory /= 10;
        num_of_digits++;
    }
    // cout << "DEBUG" << current_number << "Num of Digits" << num_of_digits << endl;
    switch (num_of_digits % 2)
    {
    // Even case
    case 0:
        if current_number & (1 << num_of_digits / 2) > (1 << (num_of_digits / 2 - 1))
        {}
        break;


    // Odd Case
    case 1:

        break;
    }
}

int main(int argc, char const *argv[])
{
    int test_cases;
    cin >> test_cases;
    int test_cases2 = test_cases;

    queue<int> mq;

    int number;
    while (test_cases--)
    {
        cin >> number;
        mq.push(number);
    }

    while (test_cases2--)
    {
        int current_number = mq.front();
        cout << next_palindrome(current_number) << endl;
        mq.pop();
    }

    return 0;
}
