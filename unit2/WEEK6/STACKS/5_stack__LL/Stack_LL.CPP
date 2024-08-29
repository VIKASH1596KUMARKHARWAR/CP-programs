#include <iostream>
using namespace std;
#include "4_StackUsingLikedList.h"
int main()
{
    StackusingLL<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << "size" << s.getSize() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << "size" << s.getSize() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    // Additional pop to demonstrate empty stack handling
    cout << s.pop() << endl; // Should print "Stack is empty. Cannot pop." and return 0 (default for int)

    StackusingLL<char> s1;
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
