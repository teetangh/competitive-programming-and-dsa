#include <iostream>
using namespace std;
// #include "solution.h"

#include <queue>
#include <stack>

void reverseQueue(queue<int> &q)
{
    // Write your code here
    stack<int> s;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    while (!s.empty())
    {
        int temp2 = s.top();
        s.pop();
        q.push(temp2);
    }
}

int main()
{
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        q.push(val);
    }
    reverseQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
