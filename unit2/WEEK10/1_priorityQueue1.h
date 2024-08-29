#include <vector>
class PriorityQueue
// assume as a tree work on an array
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0; // vector.size() - wala
    }

    // return the size of priorityQueue - no. of element present
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1; // new element jo insert hua h

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                swap(pq[parentIndex], pq[childIndex]);
                // childIndex = parentIndex;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            throw runtime_error("Priority queue is empty");
        }

        // swap rooot  with the last node of tree   and del the last element now...kyoki cbt se yhi last rightmost del hoga... maintaing last level leftmost se fill ho

        // now instead directly swapig thoda vector ka faida uthate h

        int minValue = pq[0];
        pq[0] = pq.back(); // assigning last element in root ie. at 0th index

        pq.pop_back();

        int parentIndex = 0;
        int n = pq.size();
        while (true)
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int righttChildIndex = 2 * parentIndex + 2;
            int minIndex = parentIndex;

            if (leftChildIndex < n && pq[leftChildIndex] < pq[minIndex])
            {
                minIndex = leftChildIndex;
            }

            if (righttChildIndex < n && pq[righttChildIndex] < pq[minIndex])
            {
                minIndex = righttChildIndex;
            }

            if (pq[minIndex] != pq[parentIndex])
            {
                swap(pq[minIndex], pq[parentIndex]);
                parentIndex = minIndex;
            }
            else
                break;
        }
        return minValue;
    }
};
