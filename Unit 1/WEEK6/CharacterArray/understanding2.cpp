#include<iostream>
using namespace std;
int main(){   
    /*
    char name[100];
    cout << "Enter your name: " ;
    // cin >> name;
    //hello world diya ...but output mein hello milega
    //cannot store the values with the space  and the and the new line characters

    // to over come this use cin.getline(arr_name,length, )
    //this breaks over the new line character

    cin.getline(name,100);

    cout << "Name: " << name <<endl;
*/



// ==========================================================

/*
    char  input[100];
    cin.getline(input,3);
    //firstly it automatically assign the '\0'  to last element 
    cout << input << endl;

*/


// =====================


    char  input[100];
    cin.getline(input,100,'o');//stop taking the input as soon as getting the char o while giving the input
    cout << input << endl;
} 