// for preincrement

#include <iostream>
#include "fractClass.cpp"
using namespace std;

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    ++f1;
    f1.print();
    Fraction f3 = ++(++f1);
    f1.print();
    f3.print();
}