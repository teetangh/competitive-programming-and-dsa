#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
private:
    /* data */
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
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
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack Full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
    // ~StackUsingArray();
};

// StackUsingArray::StackUsingArray(/* args */)
// {
// }

// StackUsingArray::~StackUsingArray()
// {
// }
