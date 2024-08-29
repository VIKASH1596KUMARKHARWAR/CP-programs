#include <iostream>
using namespace std;
#include <cstring>
#include "StudenrntClass2.cpp"

int main()
{
    /*
    StudentClass s1(101);
    s1.age = 10;
    //   s1.rollNumber = 101;
    cout << s1.age << " " << s1.rollNumber << endl;
    */

    StudentClass s2(24, 102);
    cout << s2.age << " " << s2.rollNumber << " " << s2.x;
}