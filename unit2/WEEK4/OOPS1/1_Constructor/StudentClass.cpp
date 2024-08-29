class Student
{
public:
    int rollNumber;

private:
    int age;

public:
    Student()
    {
        cout << "constructor called" << endl;
    }

    // Parameterized consteructor
    Student(int r)
    {
        cout << "constructor 2 is called!!" << endl;
        rollNumber = r;
    }
    Student(int a, int r)
    {
        cout << "constructor 3 is called!!" << endl;
        rollNumber = r;
        age = a;
    }

    void display()
    {
        cout << age << " " << rollNumber << endl;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int a)
    {
        // if(password!=123){
        //     return;
        // }
        // if (a < 0)
        // {
        //     return;
        // }
        age = a;
    }
};