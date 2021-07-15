// Well actually this is Circular Queue

#include <iostream>
using namespace std;
template <typename T>
class QueueUsingArray
{
private:
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];

        firstIndex = -1;
        nextIndex = 0;
        
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
            cout << "Queue Full" << endl;
            return;
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

    // ~QueueUsingArray();
};
