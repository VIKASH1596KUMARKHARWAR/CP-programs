#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int currentSize;

public:
    Deque(int size)
    {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = 0;
        currentSize = 0;
    }

    void insertFront(int element)
    {
        if (isFull())
        {
            cout << -1 << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        {
            front = capacity - 1;
        }
        else
        {
            front--;
        }

        arr[front] = element;
        currentSize++;
    }

    void insertRear(int element)
    {
        if (isFull())
        {
            cout << -1 << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = element;
        currentSize++;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << -1 << endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        currentSize--;
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << -1 << endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = capacity - 1;
        }
        else
        {
            rear--;
        }

        currentSize--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    bool isFull()
    {
        return currentSize == capacity;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    ~Deque()
    {
        delete[] arr;
    }
};
// C++ implementation of De-queue using circular
// array

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            dq.insertFront(input);
            break;
        case 2:
            cin >> input;
            dq.insertRear(input);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            cout << dq.getFront() << "\n";
            break;
        case 6:
            cout << dq.getRear() << "\n";
            break;
        default:
            return 0;
        }
    }

    return 0;
}
