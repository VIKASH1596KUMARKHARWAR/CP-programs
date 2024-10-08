#include <vector>
#include <climits>
class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
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

    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty())
        {
            return INT_MIN; // Return -Infinity if queue is empty
        }
        return pq[0];
    }

    int removeMax()
    {
        // Implement the removeMax() function here

        int maxValue = pq[0];
        pq[0] = pq.back();
        pq.pop_back();
        int parentIndex = 0;

        int n = pq.size();
        while (true)
        {
            int leftChildIndex = 2 * parentIndex + 1;
            int rightChildIndex = 2 * parentIndex + 2;
            int maxIndex = parentIndex;

            if (leftChildIndex < n && pq[leftChildIndex] > pq[maxIndex])
            {
                maxIndex = leftChildIndex;
            }

            if (rightChildIndex < n && pq[rightChildIndex] > pq[maxIndex])
            {
                maxIndex = rightChildIndex;
            }

            if (maxIndex != parentIndex)
            {
                swap(pq[parentIndex], pq[maxIndex]);
                parentIndex = maxIndex;
            }
            else
            {
                break;
            }
        }
        return maxValue;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.empty();
    }
};
#include <iostream>
using namespace std;

#include "solution.h"

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
            cout << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMax() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}