#include <iostream>
#include "../include/TemplateStack.hpp"
using namespace std;


bool checkBalanced(char *exp)
{
    // int length = lengthOfExp(exp);

    StackUsingArray<char> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        // cout << "current Stack" << endl;
        // s.printStack();

        if (s.isEmpty() && (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'))
        {
            return false;
        }
        else if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (exp[i] == ')' && s.top() != '(')
                return false;
            if (exp[i] == '}' && s.top() != '{')
                return false;
            if (exp[i] == ']' && s.top() != '[')
                return false;
            else
                char temp = s.pop();
        }
    }
    if (s.isEmpty())
        return true;
    else
        return false;
}
int main()
{
    char input[100000];
    cin.getline(input, 100000);
    //    cin >> input;
    if (checkBalanced(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
