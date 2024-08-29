#include <iostream>
using namespace std;
#include <cstring>
#include "StudentClass1.cpp"

int main()
{
    char name[] = "abcd";
    StudentClass s1(20, name);
    s1.display();

    StudentClass s2(s1); // copy constructor --< swallo copy >
                         // we will make our own copy consructor
    s2.name[0] = 'x';
    s2.display();
    s1.display();
}