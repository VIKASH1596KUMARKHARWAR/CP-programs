#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue
{
private:
    vector<pair<int, string>> heap; // Pair of (priority, value)

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent].first < heap[index].first)
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int index)
    {
        int n = heap.size();
        while (true)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int maxIndex = index;

            if (leftChild < n && heap[leftChild].first > heap[maxIndex].first)
            {
                maxIndex = leftChild;
            }

            if (rightChild < n && heap[rightChild].first > heap[maxIndex].first)
            {
                maxIndex = rightChild;
            }

            if (maxIndex != index)
            {
                swap(heap[index], heap[maxIndex]);
                index = maxIndex;
            }
            else
            {
                break;
            }
        }
    }

public:
    void push(int priority, const string &value)
    {
        heap.push_back(make_pair(priority, value));
        heapifyUp(heap.size() - 1);
    }

    string pop()
    {
        if (heap.empty())
        {
            throw runtime_error("Priority queue is empty");
        }

        string maxValue = heap[0].second;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxValue;
    }

    bool empty() const
    {
        return heap.empty();
    }
};
/*
int main()
{
    PriorityQueue pq;

    pq.push(5, "task1");
    pq.push(1, "task2");
    pq.push(3, "task3");

    cout << pq.pop() << endl; // Output: task1
    cout << pq.pop() << endl; // Output: task3
    cout << pq.pop() << endl; // Output: task2

    // Uncomment below to test empty case
    // cout << pq.pop() << endl;  // Throws runtime_error: Priority queue is empty

    return 0;
}
*/