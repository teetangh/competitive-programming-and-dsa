#include <vector>
using namespace std;

// This is actually a minPriorityQueue
class PriorityQueue
{
private:
    vector<int> pq;

public:
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

    // Returns the minimum element in the priority Queue
    int getMin()
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

            if (pq[childIndex] < pq[parentIndex])
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

    PriorityQueue()
    {
    }
    ~PriorityQueue();
};