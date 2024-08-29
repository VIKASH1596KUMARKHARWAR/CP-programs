// header file should not have main
// aab yeh khi bhi use ho shakte h
// double court while importing means search withing the same folder
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next; // pointer banate time template dena h

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class StackusingLL
{
    // data members
    Node<T> *head;
    int size;

public:
    StackusingLL()
    {
        // initialise in constructor--> nhi toh wo static ho jayenge (IN DO IN INITIALISATION_F0_MEMBER )
        head = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool is_empty()
    {
        return size == 0;
    }

    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        if (is_empty())
        {
            cerr << "Stack is empty. Cannot pop." << endl;
            return T(); // Return default constructed T (0 for int, nullptr for pointers, etc.)
        }
        T poppedVal = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return poppedVal;
    }

    T top()
    {
        if (is_empty())
        {
            cerr << "Stack is empty. Cannot pop." << endl;
            return T(); // Return default constructed T (0 for int, nullptr for pointers, etc.)
        }
        return head->data;
    }
};
