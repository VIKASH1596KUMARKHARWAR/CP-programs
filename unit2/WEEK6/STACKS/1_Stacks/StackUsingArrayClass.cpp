#include <climits>

class Stack
{
private:
    int *data;
    int nextIndex;
    int capacity;

public:
    Stack(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // return the number of elements present in the stacks
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        /*  if(nextIndex ==0) return true;
            else  return false;
       */
        return nextIndex == 0;
    }

    // insert Element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack is Full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // Delete elelment
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
