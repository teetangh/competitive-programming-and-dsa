#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int query_answer(priority_queue<int, vector<int>, greater<int>> mpq, int counter, int current_query)
{
    int current_query_answer;
    while (counter < current_query)
    {
        counter++;
        current_query_answer = mpq.top();
        mpq.pop();
        if (current_query_answer / 2 > 0)
            mpq.push(current_query_answer / 2);
    }

    return current_query_answer;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    int array_size, queries;
    cin >> array_size >> queries;

    int current_query;

    int counter = 0;
    priority_queue<int, vector<int>, greater<int>> mpq;
    while (queries--)
    {
        cin >> current_query;
        mpq.push(current_query);
        cout << query_answer(mpq, counter, current_query) << endl;
    }

    return 0;
}
