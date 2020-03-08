#include <iostream>
using namespace std;
#include "TemplateStack.cpp"

int main()
{
    //Integer Stack
    StackUsingArray<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << s1.top() << endl;

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    cout << s1.size() << endl;
    cout << s1.isEmpty() << endl;

    //Character Stack
    StackUsingArray<char> s2;
    s2.push(100);
    s2.push(101);
    s2.push(102);
    s2.push(103);
    s2.push(104);

    cout << s2.top() << endl;

    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;

    cout << s2.size() << endl;
    cout << s2.isEmpty() << endl;
}