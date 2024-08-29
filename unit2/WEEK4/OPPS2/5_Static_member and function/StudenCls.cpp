#include <iostream>
using namespace std;
class StudentCls
{
    static int totalStudents; // total no. of students Present

public:
    int rollnumber;
    int age;

    StudentCls()
    { // esme daala to cunt student created at each level..bcz default construcotr toh har baar create hoga--when no parameter given at time of object defining
        totalStudents++;
    }

    int getRolNumber()
    {
        return rollnumber;
    }
    static int gettotalStudents()
    {
        return totalStudents;
    }
};

int StudentCls ::totalStudents = 0; // initialise static data member