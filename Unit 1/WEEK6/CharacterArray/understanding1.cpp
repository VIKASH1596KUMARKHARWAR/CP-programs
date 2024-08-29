#include<iostream>
using namespace std;
int main(){
    /*
    char name[100];
    cout << "Enter your name: " ;
    cin >> name;
    cout << "Name: " << name <<endl;
    */
/*
   char name[100];
    cout << "Enter your name: " ;
    cin >> name;//abc
    name[4] = 'X';//still gives abc...
    cout << "Name: " << name <<endl;
*/

/*
//Now let hum /0 ki jgh ie. at index 3 we put 'd' 
   char name[100];
    cout << "Enter your name: " ;
    cin >> name;//abc
    name[4] = 'X';
    name[3] = 'd';
    cout << "Name: " << name <<endl;
*/


//Now let hum b ki jgh ie. at index 2 we put '\0' 
   char name[100];
    cout << "Enter your name: " ;
    cin >> name;//abc
    name[4] = 'X';
    name[3] = 'd';
    name[1]='\0';
    cout << "Name: " << name <<endl;//a

}