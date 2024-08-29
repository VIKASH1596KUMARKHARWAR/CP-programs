/*TYEPE OF CONSRUCTORS
 1.DEFAULT,

 2.COPY(kisi type (static/dynamic obj) ko kisi mein bhi copy kiya jaa shakta hain ),

 3.COPY ASSIGNMENT OPERATOR(=)


    DESTRUCTOR:Jo hamare obj ki allocated memory h use deallocate krwana
         --same name as our class
         --no return type,no input argument
         --Defult contructor k aage ~(telda operator)
         --like constructr...it also called at once in  lifetime of an obj
         --called automatically for the statically define objects but for the dyaminc one need to do explicitely
                    `use   delete object_name` yeh pointer jb  khud free hoga tb toh destructor ko call kr lega
*/

#include <iostream>
using namespace std;
#include "StudentClass1.cpp"
int main()
{
    /*   cout << " FOR STUDENT 1 " << endl;
        Students ss1(100, 1200);
        ss1.display();

        cout << " FOR STUDENT 2 " << endl;
        Students ss2(ss1);
        // copyc onstructor--> no call to any consrucotr with single arg of Student class type🙃
        ss2.display();

        cout << " FOR STUDENT 3 " << endl;
        Students *ss3 = new Students(2, 100);

        ss3->display();

        cout << " FOR STUDENT 4 " << endl;

        Students ss4(*ss3); // copying dynamic in static
        ss4.display();

        cout << " FOR STUDENT 5 " << endl;
        Students *ss5 = new Students(*ss3); // copying  d in d
        ss5->display();

        cout << " FOR STUDENT 6 " << endl;
        Students *ss6 = new Students(ss1); // copying stactic into dynamic
        ss6->display();
    */

    // 3rd construcotr(=)
    Students s1(10, 1001);
    Students s2(10, 1001);
    Students *s3 = new Students(30, 3001);

    s2 = s1;  // s to s
    *s3 = s1; // s to d
    s2 = *s3; // d to s

    // once after creating object with some diff vale at some point we need to s2 have same value of s1 so called 3rd typConst..

    delete s3; // Explicitely deleteing the memory allocated to dyanamically created obj
}
