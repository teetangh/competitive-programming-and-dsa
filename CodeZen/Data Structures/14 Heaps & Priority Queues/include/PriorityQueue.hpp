#include <vector>
using namespace std;

// This is actually a minPriorityQueue
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
    int CNremoveMin()
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
            int minIndex = parentIndex;

            if (pq[minIndex] > pq[leftChildIndex])
                minIndex = leftChildIndex;
            if (rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
                minIndex = rightChildIndex;

            // In case the above the above 2 if's failed
            // then the parent is at its correct position
            if (minIndex == parentIndex)
                break;

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }

    //Delete from Heap and DOWN-HEAPIFY (or RemoveMin)
    int MYremoveMin()
    {
        int ans = pq[0];
        int parentIndex = 0;
        swap(pq[parentIndex], pq[pq.size() - 1]);
        pq.pop_back(); // to remove the last min element
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex && rightChildIndex < pq.size())
        {
            int minIndex = parentIndex; //should be inside loop because it's dynamic
            int minValue = min(pq[parentIndex], min(pq[leftChildIndex], pq[rightChildIndex]));

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

        if (leftChildIndex < pq.size() && rightChildIndex >= pq.size())
        {
            int minValue = min(pq[parentIndex], pq[leftChildIndex]);
            if (minValue == pq[parentIndex])
                return ans;
            else if (minValue == pq[leftChildIndex])
                swap(pq[parentIndex], pq[leftChildIndex]);
        }

        return ans;
    }

    int removeMin2()
    {
        int ans = pq[0];
        int parentIndex = 0;
        swap(pq[parentIndex], pq[pq.size() - 1]);
        pq.pop_back();
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex && rightChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            int minValue = min(pq[parentIndex], min(pq[leftChildIndex], pq[rightChildIndex]));

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

    int removeMin3()
    {
        int ans = pq[0];
        int parentIndex = 0;
        pq[parentIndex] = pq[pq.size() - 1];
        pq.pop_back();

        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
                minIndex = leftChildIndex;
            if (rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            swap(pq[parentIndex], pq[minIndex]);

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};