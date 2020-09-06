// Well actually this is Circular Queue

#include <iostream>
using namespace std;
template <typename T>
class DynamicQueueUsingArray
{
private:
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    DynamicQueueUsingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity;)
            {
                newData[j++] = data[i++];
            }
            for (int i = 0; i < firstIndex;)
            {
                newData[j++] = data[i++];
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            // cout << "Queue Full" << endl;
            // return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
            firstIndex = 0;
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        // Reseting the Queue
        if (isEmpty())
        {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }

    // ~DynamicQueueUsingArray();
};
