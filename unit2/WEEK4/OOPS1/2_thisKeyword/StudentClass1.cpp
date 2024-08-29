class Students
{
public:
    int rollNumber_;

private:
    int age_;

public:
    ~Students()
    {
        cout << "Destructure called!!" << endl;
    }
    Students()
    {
        cout << "constructor 1 is  called!!" << endl;
    }
    Students(int rollNumber_)
    {
        cout << "constructor 2 is called!!" << endl;
        this->rollNumber_ = rollNumber_;
    }
    Students(int a, int r)
    {
        cout << "constructor 3 is called!!" << endl;
        rollNumber_ = r;
        this->age_ = a; // age_ = a
    }

    void display()
    {
        cout << "age " << age_ << " rollnumber " << rollNumber_ << endl;
    }
};