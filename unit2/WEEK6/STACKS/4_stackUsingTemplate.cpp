#include <iostream>
using namespace std;

template <typename T>
class StackUsingTEMPlate
{
private:
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingTEMPlate()
    {
        capacity = 4; //  capacity
        data = new T[capacity];
        nextIndex = 0;
        }

    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
    {
        if (nextIndex == 0)
        {
            cerr << "Stack is empty. Cannot pop." << endl;
            return T(); // Return default constructed T (0 for int, nullptr for pointers, etc.)
        }
        nextIndex--;
        return data[nextIndex];
    }

    // Add a function to check if the stack is empty
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Destructor to free dynamically allocated memory
    ~StackUsingTEMPlate()
    {
        delete[] data;
    }
};

int main()
{
    StackUsingTEMPlate<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    // Additional pop to demonstrate empty stack handling
    cout << s.pop() << endl; // Should print "Stack is empty. Cannot pop." and return 0 (default for int)

    StackUsingTEMPlate<char> s1;
    s1.push('A');
    s1.push('B');
    s1.push('C');
    s1.push('D');
    s1.push('E');

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    // Additional pop to demonstrate empty stack handling
    cout << s1.pop() << endl; // Should print "Stack is empty. Cannot pop." and return 0 (default for int)

    return 0;
}
