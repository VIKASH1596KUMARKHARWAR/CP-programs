#include <iostream>
using namespace std;
class StudentClass
{
private:
    int age;

public:
    char *name;

    StudentClass(int age, char *name)
    {
        this->age = age;

        // deep copy krna chahiye
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void display()
    {
        cout << name << " " << age << endl;
    }

    // our own copy constuctor
    StudentClass(StudentClass const &s)
    {
        this->age = s.age;
        // aab deep copy krdo
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, s.name);
    }
};