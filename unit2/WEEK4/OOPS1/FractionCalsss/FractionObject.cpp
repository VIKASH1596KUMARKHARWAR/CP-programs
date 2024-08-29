#include <iostream>
#include "FractionClass.cpp"
using namespace std;

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);
    cout << "f1: ";
    f1.print();
    cout << "f2: ";
    f2.print();
    cout << "add: ";
    f1.addFraction(f2); // f1=f1+f2
    cout << "f1: ";
    f1.print();
    cout << "f2: ";
    f2.print();

    f1.multiply(f2);
    f1.print();
    f2.print();

    return 0;
}