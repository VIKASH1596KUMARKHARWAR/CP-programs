#include <iostream>
using namespace std;
#include "StudentClass.cpp"
int main()
{
    Student s1; // jb bhii object banaya inbuit /default constructor call hoga

    s1.display();

    Student s2; // gb

    Student *s3 = new Student;
    s3->display(); // gb

    cout << "Parameterized Construcotrs Demo" << endl;

    Student s4(10); // aab default constructor nhi call hoga,jo hume banaya h wo call hoga

    s4.display();

    Student *s5 = new Student(5);
    s5->display();

    Student s6(120, 256);
    s6.display();
}

// Note : ek object k liye ek hi constructor call hoga either, inbuilt default wala ya parametised walle and remember ek object k liye ek hi constructor call hoga ...wo hi most probably  at the time of their initialisation.

/*note2... what if agar ham  jo Student(){}--ie. unparametrised constructor tha use delete kr de from class toh will at the time of creating object
    Student s1;
will call inbuilt walla constructor...r we able to acces after ,making any paramerterised construcotr.

the answer is error..yes we will get error as we are o longet able to use hat inbilt constructor.

==>> no matching constructrs for initialisation of Student s1
==>> no matching constructrs for initialisation of Studentr s2
==>> no matching constructrsfor initialisation of Student s3

 -----with zero wala argument to  initailise them with some values or by garbage value(bcz inbilt wala bhi aab access mein nhi hain) aur koi hamara banaya hua bhi constructor with 0 arg nhi h..



if u want to make visible  the default wala construcotr hame claass k ander likha padega...we have to explecitally create i t
*/
