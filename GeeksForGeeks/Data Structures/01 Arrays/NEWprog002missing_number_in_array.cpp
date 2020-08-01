#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test_cases;
    cin >> test_cases;

    queue<int> my_queue;

    while (test_cases--)
    {
        int last_num;
        cin >> last_num;

        int prev, current;
        cin >> prev;
        for (int counter = 0; counter < last_num - 2; counter++)
        {
            cin >> current;

            if ((current - prev) >= 2)
                my_queue.push(int(prev + 1));

            prev = current;
        }
    }

    while (!(my_queue.empty()))
    {
        int temp = my_queue.front();
        my_queue.pop();
        cout << temp << endl;
    }
    return 0;
}