#include<iostream>
using namespace std;

int main(){

//q1
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl;//ans.b--malipulation of a

//q2
    char b[] = "xyz";
    char *c = &b[0];
    cout << c << endl;  //xyz

//q3
    char b[] = "xyz";
    char *c = &b[0];
    c++;
    cout << c << endl;//yz   

//q4
    char s[]= "hello";
    char *p = s;
    cout << s[0] << " " << p[0];//h h 


}


