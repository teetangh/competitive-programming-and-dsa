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
    StackUsingArray()
    {
        capacity = 4;
        data = new int[capacity];
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
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
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
