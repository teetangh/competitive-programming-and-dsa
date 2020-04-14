#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{

private:
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    // Checks if the Priority Queue is empty
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // Return the size of priorityQueue - no of elements present
    int getSize()
    {
        return pq.size();
    }

    // Returns the maximum element in the priority Queue
    int getMax()
    {
        // In case Priority Queue is Empty
        if (isEmpty())
            return 0;
        return pq[0];
    }

    //Insert into Heap and UP-HEAPIFY
    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) // In case childIndex reaches the ROOT
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            // In case childIndex reaches its correct position
            // admist inserting and up-heapifying
            else
                break;

            childIndex = parentIndex;
        }

        // Removed it and placed it at the start of the while loop
        // parentIndex = (childIndex - 1) / 2;
    }

    //Delete from Heap and DOWN-HEAPIFY (or RemoveMax)
    int removeMax()
    {
        // In case PQ is empty
        if (isEmpty())
            return 0;

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // Down-Heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq.size())
        {
            int maxIndex = parentIndex;

            if (pq[maxIndex] < pq[leftChildIndex])
                maxIndex = leftChildIndex;
            if (rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex])
                maxIndex = rightChildIndex;

            // In case the above the above 2 if's failed
            // then the parent is at its correct position
            if (maxIndex == parentIndex)
                break;

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};
int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMax
            cout << pq.getMax() << endl;
            break;
        case 3: // removeMax
            cout << pq.removeMax() << endl;
            break;
        case 4: // size
            cout << pq.getSize() << endl;
            break;
        case 5: // isEmpty
            if (pq.isEmpty())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        default:
            return 0;
        }
        cin >> choice;
    }
}
