
// PLAYING WITH THE NAME--> KOI BHI ARRAY KO CHED K IN OBJECT FILE CHANGE KR SHAKTA H !! USSE KAISE RESTRICT KRE!!

#include <iostream>
using namespace std;
class StudentClass
{
private:
    int age;
    char *name;

public:
    StudentClass(int age, char *name)
    {
        this->age = age;

        // SHALLOW COPY(aur ese avoid krna chahiye)
        // this->name = name;

        // deep copy krna chahiye
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void display()
    {
        cout << name << " " << age << endl;
    }
};