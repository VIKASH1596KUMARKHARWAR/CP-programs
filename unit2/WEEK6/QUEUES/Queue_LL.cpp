#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {
        Node *temp = new Node(data);
        if (isEmpty())
        {
            head = tail = temp;
        }
        tail->next = temp;
        tail = temp;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }

        int val = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;

        if (isEmpty())
        {
            tail = nullptr;
        }

        return val;
    }

    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->data;
    }
};
#include <iostream>
using namespace std;

int main()
{
    Queue q;

    int t;
    cin >> t;

    while (t--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            q.enqueue(input);
            break;
        case 2:
            cout << q.dequeue() << "\n";
            break;
        case 3:
            cout << q.front() << "\n";
            break;
        case 4:
            cout << q.getSize() << "\n";
            break;
        default:
            cout << ((q.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}