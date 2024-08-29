#include <iostream>
using namespace std;
class StudentClass
{
public:
    int age;
    const int rollNumber;
    int &x; // age reference variable

    // StudentClass(int r) : rollNumber(r) {} // const type ko initialise krne k liye at time of memory allocaion

    // ex 2:
    //  StudentClass(int age, int rollNumber) : rollNumber(rollNumber), age(age) {}

    // reference variable
    StudentClass(int r, int age) : rollNumber(r), age(age), x(this->age) {}
};