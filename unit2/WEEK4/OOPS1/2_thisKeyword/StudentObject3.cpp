#include <iostream>
using namespace std;
#include "StudentClass1.cpp"
int main()
{
    Students s1;          // c1
    Students s2(101);     // c2
    Students s3(20, 102); // c3
    Students s4(s3);      // copy constructor

    s1 = s2; // no additional construcotr is calling--assignment operator

    Students s5 = s4; // copy constructor(notes)
}