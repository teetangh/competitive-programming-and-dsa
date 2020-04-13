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

    //Delete from Heap and DOWN-HEAPIFY (or RemoveMin)
    int removeMin()
    {
        // Complete this function
        int ans = pq[0];

        int parentIndex = 0;

        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        int minIndex = parentIndex;
        while (leftChildIndex && rightChildIndex < pq.size())
        {
            int minValue = min(pq[parentIndex], pq[leftChildIndex], pq[rightChildIndex]);

            if (minValue == pq[parentIndex])
                return ans;
            else if (minValue == pq[leftChildIndex])
                minIndex = leftChildIndex;
            else
                minIndex = rightChildIndex;

            swap(pq[parentIndex], pq[minIndex]);

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }

    PriorityQueue()
    {
    }
    ~PriorityQueue();
};