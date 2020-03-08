#include <iostream>
using namespace std;
// #include "solution.h"
template <typename T>
class StackUsingArray
{
private:
    /* data */
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }
    // return the number of elements present in my stack
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        // if (nextIndex == 0)
        //     return true;
        // else
        //     return false;
        return (nextIndex == 0);
    }
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
            // cout << "Stack Full" << endl;
            // return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if (isEmpty())
        {
            // cout << "Stack is Empty" << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            // cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
    void printStack()
    {
        for (int i = 0; i < nextIndex; i++)
            cout << data[i] << " ";
        cout << endl;
    }
    // ~StackUsingArray();
};
// int lengthOfExp(char *exp)
// {
//     int count = 0;
//     for(int i = 0; exp[i] !='\0';i++)
//         count++;
//     return count;
// }

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
