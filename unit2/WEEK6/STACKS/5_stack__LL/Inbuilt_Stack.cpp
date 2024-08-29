#include <iostream>
using namespace std;
// #include "4_StackUsingLikedList.h"
#include <stack> //yeh bhi company dwatra emplate se bana h
int main()
{

    /*
More about inbult stack ::
    pop->only delete(inbuilt pop is of void type)
            toh pehele top element access kr lenge ...print like
            and then pop() call krenge
    isEmpty() nhi bool empty()  --->just name change h
    */
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Stack 1 : " << endl
         << "size = " << s.size() << endl
         << s.empty() << endl;

    cout << s.top() << endl;

    stack<char> s1;
    s1.push('A');
    s1.push('B');
    s1.push('C');
    s1.push('D');
    s1.push('E');

    cout << "Stack 2 : " << endl
         << s1.top() << endl;

    s1.pop(); // Delete E
    cout << s1.top() << endl;

    return 0;
}
