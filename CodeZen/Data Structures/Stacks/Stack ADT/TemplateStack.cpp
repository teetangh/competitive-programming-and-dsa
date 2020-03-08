#include <iostream>
#include <climits>
using namespace std;

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
            cout << "Stack is Empty" << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
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
