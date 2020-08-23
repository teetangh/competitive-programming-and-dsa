#include <iostream>
using namespace std;
// #include "solution.h"

#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra)
{
    // Write your code here
    stack<int> extra2;
    while (!input.empty())
    {
        int temp = input.top();
        input.pop();
        extra.push(temp);
    }
    while (!extra.empty())
    {
        int temp2 = extra.top();
        extra.pop();
        extra2.push(temp2);
    }
    while (!extra2.empty())
    {
        int temp3 = extra2.top();
        extra2.pop();
        input.push(temp3);
    }
}

int main()
{
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        s1.push(val);
    }
    reverseStack(s1, s2);
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}
