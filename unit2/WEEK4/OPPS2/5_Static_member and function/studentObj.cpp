#include <iostream>
using namespace std;
#include "StudenCls.cpp"
int main()
{
    StudentCls s1;
    StudentCls s2;

    StudentCls s3, s4, s5;
    // cout << StudentCls ::totalStudents << endl; //static data member

    cout << StudentCls::gettotalStudents() << endl; // static fuction
}