#include <iostream>
using namespace std;
#include "StudentClass1.cpp"
int main()
{

    // this keyword store theaddres of current class
    Students ss1(100, 1200); // jb bhii object banaya inbuit/default constructor call hoga

    cout << "Address of s1: " << &ss1 << endl;
    ss1.display();

    Students ss2(122);
    cout << "Address of s2: " << &ss2 << endl;
    ss2.display();
}
