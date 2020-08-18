#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int query_answer(vector<int> arr, queue<int> my_queue, int counter, int current_query)
{
    int current_max;
    int current_query_answer = 0;

    while (counter < current_query && (!arr.empty() || !my_queue.empty()))
    {
        counter++;
        if (arr.empty())
        {
            current_max = my_queue.front();
            my_queue.pop();
            if (current_max / 2 > 0)
                my_queue.push(current_max / 2);
        }

        else if (arr.back() >= my_queue.front())
        {
            current_query_answer = current_max = arr.back();
            arr.pop_back();
            if (current_max / 2 > 0)
                my_queue.push(current_max / 2);
        }
        else if (arr.back() < my_queue.front())
        {
            current_query_answer = current_max = my_queue.front();
            my_queue.pop();
            if (current_max / 2 > 0)
                my_queue.push(current_max / 2);
        }
    }

    return current_query_answer;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int size, queries;
    cin >> size >> queries;

    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), std::less<int>());

    int counter = 0;
    int current_query;
    queue<int> my_queue;

    while (queries--)
    {
        cin >> current_query;
        cout << query_answer(arr, my_queue, counter, current_query) << endl;
    }

    return 0;
}
