#include <iostream>
using namespace std;
#include <cstring>
#include "StudentClass.cpp"

int main()
{
    char name[] = "abcd";
    StudentClass s1(20, name);
    s1.display();

    /*name[4] = 'e';
    name[5] = '\0';*/

    name[3] = 'e';
    StudentClass s2(24, name);
    s2.display();
    s1.display();
}