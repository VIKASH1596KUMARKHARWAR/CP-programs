#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue
{
private:
    vector<int> pq;

    void heapifyUp(int childIndex)
    {
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex])
            {
                swap(pq[parentIndex], pq[childIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int parentIndex)
    {
        int n = pq.size();
        while (true)
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int minIndex = parentIndex;

            if (leftChildIndex < n && pq[leftChildIndex] < pq[minIndex])
            {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < n && pq[rightChildIndex] < pq[minIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex != parentIndex)
            {
                swap(pq[parentIndex], pq[minIndex]);
                parentIndex = minIndex;
            }
            else
            {
                break;
            }
        }
    }

public:
    PriorityQueue() {}

    bool isEmpty()
    {
        return pq.empty();
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            throw runtime_error("Priority queue is empty");
        }
        return pq[0];
    }

    void insert(int value)
    {
        pq.push_back(value);
        heapifyUp(pq.size() - 1);
    }

    int removeMin()
    {
        if (isEmpty())
        {
            throw runtime_error("Priority queue is empty");
        }

        int minValue = pq[0];
        pq[0] = pq.back();
        pq.pop_back();
        heapifyDown(0);

        return minValue;
    }
};
/*
int main()
{
    PriorityQueue pq;

    pq.insert(5);
    pq.insert(1);
    pq.insert(3);

    cout << pq.removeMin() << endl; // Output: 1
    cout << pq.removeMin() << endl; // Output: 3
    cout << pq.removeMin() << endl; // Output: 5

    // Uncomment below to test empty case
    // cout << pq.removeMin() << endl;  // Throws runtime_error: Priority queue is empty

    return 0;
}
*/